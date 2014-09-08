#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<windows.h>
#include"GUI.h"
#include<stdlib.h>
#include"environment.h"
#include "player54097023.h"

using namespace std;
using namespace GUI;

const int NEWGAME_BTN_ID = 102, SELECTMAP_BTN_ID = 103, DISPLAY_BTN_ID = 104, NEWMAP_BTN_ID = 105;
const int NEWMAP_OK_BTN_ID = 202, NEWMAP_CANCEL_BTN_ID = 203;
const int SELECTMAP_SELECT_ID = 302, SELECTMAP_CANCEL_BTN_ID = 303;
const int DO_ONE_STEP_BTN_ID = 402, DO_ONE_RUN_BTN_ID = 403, NEXT_RUN_BTN_ID = 404, DO_ALL_RUN_BTN_ID = 405;
const int CURSOR_UP_BTN_ID = 500, CURSOR_DOWN_BTN_ID = 501, CURSOR_LEFT_BTN_ID = 502, CURSOR_RIGHT_BTN_ID = 503, REINICIAR_BTN_ID = 504;
const int ERROR_OK_BTN_ID = 602;

int main_window;
char life_time_input[1000] = "2000", total_runs_input[1000] = "10", file_name_input[1000] = "mapita10a.map";
char display_step[20] = "10", display_time[20] = "10";
char life_time_temp[1000], total_runs_temp[1000], file_name_temp[1000];
int tx, ty, tw, th;
float magnification_x, magnification_y;
long long life_time = 2000, current_time, total_runs = 10, current_run, dirty_degree, consumed_energy;
long long total_dirty_degree, total_consumed_energy;
char time_step_msg[100], action_msg[100], dirty_degree_msg[100], consumed_energy_msg[100];

int JugadorActivo = 1;
int human1, human2;

Environment *env = NULL;
Player54097023 *player1 = NULL;
Player54097023 *player2 = NULL;
Environment::ActionType action = Environment::actIDLE;
ifstream fin;

GLUI *main_glui, *score_glui, *new_map_glui, *select_map_glui, *error_glui, *cursor_glui;
GLUI_Button *new_map_btn, *select_map_btn, *new_map_ok_btn, *new_map_cancel_btn;
GLUI_Button *do_one_step_btn, *display_btn, *do_one_run_btn, *next_run_btn, *do_all_run_btn;
GLUI_Button *cursor_up, *cursor_down, *cursor_left, *cursor_right;
GLUI_Button *reiniciar_btn;
GLUI_StaticText *time_step_text, *action_text, *dirty_degree_text, *consumed_energy_text;
GLUI_StaticText *complete_runs_text, *total_score_text, *average_score_text, *juega_txt;
GLUI_FileBrowser *map_list;
GLUI_RadioGroup *radio1, *radio2;
GLUI_Panel *obj_panel1, *obj_panel2;

void GUI::myGlutReshape(int w, int h) {
    GLUI_Master.get_viewport_area(&tx, &ty, &tw, &th);
    glViewport(tx, ty, tw, th);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (tw <= th) {
        magnification_x = 1;
        magnification_y = (GLfloat) th / (GLfloat) tw;
    } else {
        magnification_x = (GLfloat) tw / (GLfloat) th;
        magnification_y = 1;
    }
    glOrtho(-10.0 * magnification_x, 10.0 * magnification_x, -10.0 * magnification_y, 10.0 * magnification_y, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void GUI::myGlutDisplay() {
    glClearColor(200.0 / 255, 200.0 / 255, 200.0 / 255, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
    if (env != NULL) {
        env->Show(tw, th);
        showScore();
    }
    glFlush();
    glutSwapBuffers();
}

bool Juego_Terminado() {
    if (env->Marcador(1)>(env->Marcador(2) + env->Total_Suciedad()))
        return true;
    if (env->Marcador(2)>(env->Marcador(1) + env->Total_Suciedad()))
        return true;
    if (!(env->a_movement_is_possible(1)) and env->Marcador(2) > env->Marcador(1))
        return true;
    if (!(env->a_movement_is_possible(2)) and env->Marcador(1) > env->Marcador(1))
        return true;
    if (!(env->a_movement_is_possible(1)) and !(env->a_movement_is_possible(2)))
        return true;
}

void GUI::control_cb(int id) {
    switch (id) {
        case SELECTMAP_BTN_ID:
            select_map_btn->disable();
            strcpy(life_time_temp, life_time_input);
            strcpy(total_runs_temp, total_runs_input);
            strcpy(file_name_temp, file_name_input);
            select_map_glui = GLUI_Master.create_glui("New Game Setting", 0, 100, 100);

            obj_panel1 = new GLUI_Panel(select_map_glui, "Jugador1 (Verde)");
            radio1 = new GLUI_RadioGroup(obj_panel1, &human1, 2, control_cb);
            new GLUI_RadioButton(radio1, "Automatico");
            new GLUI_RadioButton(radio1, "Humano");

            obj_panel2 = new GLUI_Panel(select_map_glui, "Jugador2 (Azul)");
            radio2 = new GLUI_RadioGroup(obj_panel2, &human2, 2, control_cb);
            new GLUI_RadioButton(radio2, "Automatico");
            new GLUI_RadioButton(radio2, "Humano");

            map_list = new GLUI_FileBrowser(select_map_glui, "", false, SELECTMAP_SELECT_ID, control_cb);
            new_map_cancel_btn = new GLUI_Button(select_map_glui, "Cancel", NEWMAP_CANCEL_BTN_ID, control_cb);
            break;
        case DISPLAY_BTN_ID:
            for (long long t = atol(display_step); t > 0 && !Juego_Terminado(); --t) {
                doOneStep();
                myGlutDisplay();
                glutPostRedisplay();
                glutSetWindow(main_window);
                glutPostRedisplay();
                Sleep(100);
            }
            if (Juego_Terminado()) {
                do_one_run_btn->disable();
                do_one_step_btn->disable();
                cursor_up->disable();
                cursor_down->disable();
                cursor_left->disable();
                cursor_right->disable();
                display_btn->disable();
            }

            break;
        case NEWMAP_OK_BTN_ID:
            strcpy(life_time_input, life_time_temp);
            strcpy(total_runs_input, total_runs_temp);
            strcpy(file_name_input, file_name_temp);
            life_time = atol(life_time_input);
            total_runs = atol(total_runs_input);
            current_run = 1;
            total_dirty_degree = 0;
            total_consumed_energy = 0;
            newGame();
            select_map_btn->enable();
            new_map_glui->close();
            break;
        case NEWMAP_CANCEL_BTN_ID:
            select_map_btn->enable();
            new_map_glui->close();
            break;
        case SELECTMAP_SELECT_ID:
            strcpy(life_time_input, life_time_temp);
            strcpy(total_runs_input, total_runs_temp);
            strcpy(file_name_input, map_list->get_file());
            life_time = atol(life_time_input);
            total_runs = atol(total_runs_input);
            current_run = 1;
            total_dirty_degree = 0;
            total_consumed_energy = 0;
            newGame();
            select_map_btn->enable();
            select_map_glui->close();
            if (human1 == 0 and human2 == 0) {
                display_btn->enable();
                cursor_up->disable();
                cursor_down->disable();
                cursor_left->disable();
                cursor_right->disable();
            } else {
                display_btn->disable();
                cursor_up->enable();
                cursor_down->enable();
                cursor_left->enable();
                cursor_right->enable();
            }
            break;
        case SELECTMAP_CANCEL_BTN_ID:
            //new_map_btn->enable();
            select_map_btn->enable();
            select_map_glui->close();
            break;
        case DO_ONE_STEP_BTN_ID:
            doOneStep();
            break;
        case DO_ONE_RUN_BTN_ID:
            doOneRun();
            break;
        case CURSOR_UP_BTN_ID:
            if ((JugadorActivo == 1 and human1 == 1) or (JugadorActivo == 2 and human2 == 1))
                do_move(JugadorActivo, 0);
            else
                doOneStep();
            break;
        case CURSOR_DOWN_BTN_ID:
            if ((JugadorActivo == 1 and human1 == 1) or (JugadorActivo == 2 and human2 == 1))
                do_move(JugadorActivo, 1);
            else
                doOneStep();
            break;
        case CURSOR_LEFT_BTN_ID:
            if ((JugadorActivo == 1 and human1 == 1) or (JugadorActivo == 2 and human2 == 1))
                do_move(JugadorActivo, 2);
            else
                doOneStep();
            break;
        case CURSOR_RIGHT_BTN_ID:
            if ((JugadorActivo == 1 and human1 == 1) or (JugadorActivo == 2 and human2 == 1))
                do_move(JugadorActivo, 3);
            else
                doOneStep();
            break;
        case ERROR_OK_BTN_ID:
            error_glui->close();
            break;
        case REINICIAR_BTN_ID:
            newGame();
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

int GUI::startDraw(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(668, 693);

    main_window = glutCreateWindow("PRACTICA 3");
    GLUI_Master.set_glutReshapeFunc(myGlutReshape);
    glutDisplayFunc(myGlutDisplay);
    glEnable(GL_DEPTH_TEST);

    score_glui = GLUI_Master.create_glui_subwindow(main_window, GLUI_SUBWINDOW_BOTTOM);
    new GLUI_StaticText(score_glui, "");
    time_step_text = new GLUI_StaticText(score_glui, "");
    new GLUI_StaticText(score_glui, "");
    action_text = new GLUI_StaticText(score_glui, "");
    new GLUI_StaticText(score_glui, "");
    dirty_degree_text = new GLUI_StaticText(score_glui, "");
    new GLUI_StaticText(score_glui, "");
    consumed_energy_text = new GLUI_StaticText(score_glui, "");
    new GLUI_StaticText(score_glui, "");
    new GLUI_Column(score_glui, false);
    new GLUI_Column(score_glui, false);
    new GLUI_Column(score_glui, false);
    new GLUI_Column(score_glui, false);
    new GLUI_Column(score_glui, false);
    new GLUI_Column(score_glui, false);
    new GLUI_Column(score_glui, false);
    new GLUI_Column(score_glui, false);
    new GLUI_Column(score_glui, false);
    new GLUI_Column(score_glui, false);
    new GLUI_StaticText(score_glui, "");
    complete_runs_text = new GLUI_StaticText(score_glui, "");
    new GLUI_StaticText(score_glui, "");
    total_score_text = new GLUI_StaticText(score_glui, "");
    new GLUI_StaticText(score_glui, "");
    average_score_text = new GLUI_StaticText(score_glui, "");
    new GLUI_StaticText(score_glui, "");
    score_glui->set_main_gfx_window(main_window);
    main_glui = GLUI_Master.create_glui_subwindow(main_window, GLUI_SUBWINDOW_RIGHT);
    new GLUI_StaticText(main_glui, "");
    //new_map_btn=new GLUI_Button(main_glui,"NewMap",NEWMAP_BTN_ID,control_cb);
    select_map_btn = new GLUI_Button(main_glui, "SelectMap", SELECTMAP_BTN_ID, control_cb);
    new GLUI_StaticText(main_glui, "");
    do_one_step_btn = new GLUI_Button(main_glui, "DoOneStep", DO_ONE_STEP_BTN_ID, control_cb);
    do_one_step_btn->disable();
    do_one_run_btn = new GLUI_Button(main_glui, "DoOneRun", DO_ONE_RUN_BTN_ID, control_cb);
    do_one_run_btn->disable();
    //next_run_btn=new GLUI_Button(main_glui,"NextRun",NEXT_RUN_BTN_ID,control_cb);
    //next_run_btn->disable();
    //do_all_run_btn=new GLUI_Button(main_glui,"DoAllRun",DO_ALL_RUN_BTN_ID,control_cb);
    //do_all_run_btn->disable();
    new GLUI_StaticText(main_glui, "");
    reiniciar_btn = new GLUI_Button(main_glui, "Reiniciar", REINICIAR_BTN_ID, control_cb);
    new GLUI_StaticText(main_glui, "");
    new GLUI_StaticText(main_glui, "");
    new GLUI_StaticText(main_glui, "DisplayOption");
    new GLUI_EditText(main_glui, "Steps:", display_step);
    //new GLUI_EditText(main_glui,"Time:",display_time);
    new GLUI_StaticText(main_glui, "");
    display_btn = new GLUI_Button(main_glui, "Display", DISPLAY_BTN_ID, control_cb);
    display_btn->disable();
    new GLUI_StaticText(main_glui, "");
    new GLUI_StaticText(main_glui, "");
    new GLUI_StaticText(main_glui, "");
    new GLUI_StaticText(main_glui, "");
    new GLUI_StaticText(main_glui, "");
    juega_txt = new GLUI_StaticText(main_glui, "");
    cursor_up = new GLUI_Button(main_glui, "Arriba", CURSOR_UP_BTN_ID, control_cb);
    cursor_up->disable();
    cursor_down = new GLUI_Button(main_glui, "Abajo", CURSOR_DOWN_BTN_ID, control_cb);
    cursor_down->disable();
    cursor_left = new GLUI_Button(main_glui, "Izquierda", CURSOR_LEFT_BTN_ID, control_cb);
    cursor_left->disable();
    cursor_right = new GLUI_Button(main_glui, "Derecha", CURSOR_RIGHT_BTN_ID, control_cb);
    cursor_right->disable();

    new GLUI_StaticText(main_glui, "");
    new GLUI_StaticText(main_glui, "");
    new GLUI_StaticText(main_glui, "");
    new GLUI_Button(main_glui, "Quit", 0, (GLUI_Update_CB) exit);
    main_glui->set_main_gfx_window(main_window);
    //glutDisplayFunc(myGlutDisplay);

    glutMainLoop();
    return 0;
}

void GUI::showScore() {
    ostringstream sout;

    sout.str("");
    if (JugadorActivo == 1)
        sout << "Juega VERDE";
    else
        sout << "Juega AZUL";
    juega_txt->set_text(sout.str().c_str());


    sout.str("");
    sout << "JUGADOR VERDE: " << env->Marcador(1);
    time_step_text->set_text(sout.str().c_str());

    sout.str("");
    sout << "JUGADOR AZUL: " << env->Marcador(2);
    action_text->set_text(sout.str().c_str());

    sout.str("");
    sout << "";
    dirty_degree_text->set_text(sout.str().c_str());


    sout.str("");
    sout << "";
    consumed_energy_text->set_text(sout.str().c_str());


    long long complete_runs = current_run - (current_time != life_time);
    //The Round has been completed
    sout.str("");
    sout << "Suciedad Restante: " << env->Total_Suciedad();
    complete_runs_text->set_text(sout.str().c_str());

    sout.str("");
    if (Juego_Terminado()) {
        if (env->Marcador(1) > env->Marcador(2))
            sout << "GANA EL JUGADOR VERDE";
        else if (env->Marcador(2) > env->Marcador(1))
            sout << "GANA EL JUGADOR AZUL";
        else
            sout << "SE HA PRODUCIDO UN EMPATE";
    }
    total_score_text->set_text(sout.str().c_str());

    sout.str("");
    sout << "";
    average_score_text->set_text(sout.str().c_str());


}

void GUI::doOneStep() {
    if (!Juego_Terminado()) {
        if (JugadorActivo == 1) {
            if (human1 == 0) {

                if (JugadorActivo == 1) {
                    player1->Perceive(*env);

                    action = player1->Think();
                    env->AcceptAction(1, action);
                    JugadorActivo = 2;
                }
            }
        } else {
            if (human2 == 0) {

                if (JugadorActivo == 2) {
                    player2->Perceive(*env);

                    action = player2->Think();
                    env->AcceptAction(2, action);

                    JugadorActivo = 1;
                }

            }
        }
    } else {
        do_one_run_btn->disable();
        do_one_step_btn->disable();
        cursor_up->disable();
        cursor_down->disable();
        cursor_left->disable();
        cursor_right->disable();
        display_btn->disable();
    }
}

void GUI::do_move(int jugador, int accion) {
    env->AcceptAction(JugadorActivo, static_cast<Environment::ActionType> (accion));

    myGlutDisplay();
    Sleep(100);

    if (JugadorActivo == 1)
        JugadorActivo = 2;
    else
        JugadorActivo = 1;
}

void GUI::doOneRun() {
    do_one_run_btn->disable();

    while (!Juego_Terminado()) {
        doOneStep();
    }

    do_one_step_btn->disable();
    cursor_up->disable();
    cursor_down->disable();
    cursor_left->disable();
    cursor_right->disable();
    display_btn->disable();
}

void GUI::newGame() {
    fin.close();
    fin.clear();
    delete env;
    //delete agent1;
    delete player2;
    delete player1;
    //delete rng;
    //delete evaluator;

    fin.open(file_name_input);
    if (fin) {
        current_time = 0;
        dirty_degree = 0;
        consumed_energy = 0;
        env = new Environment(fin);
        player1 = new Player54097023(1);
        player2 = new Player54097023(2);


        JugadorActivo = rand() % 2 + 1;

        do_one_step_btn->enable();
        display_btn->enable();
        do_one_run_btn->enable();
        cursor_up->enable();
        cursor_down->enable();
        cursor_left->enable();
        cursor_right->enable();
    } else {
        fin.clear();
        char temp[1000] = {"map/"};
        strcat(temp, file_name_input);
        fin.open(temp);
        if (fin) {
            current_time = 0;
            dirty_degree = 0;
            consumed_energy = 0;
            env = new Environment(fin);
            player1 = new Player54097023(1);
            player2 = new Player54097023(2);

            JugadorActivo = rand() % 2 + 1;

            do_one_step_btn->enable();
            display_btn->enable();
            do_one_run_btn->enable();
            cursor_up->enable();
            cursor_down->enable();
            cursor_left->enable();
            cursor_right->enable();
        } else {
            do_one_step_btn->disable();
            display_btn->disable();
            do_one_run_btn->disable();
            cursor_up->disable();
            cursor_down->disable();
            cursor_left->disable();
            cursor_right->disable();
            error_glui = GLUI_Master.create_glui("Error", 0, 100, 100);
            char error_message[1000] = "File ";
            strcat(error_message, file_name_input);
            strcat(error_message, " can't be open");
            new GLUI_StaticText(error_glui, error_message);
            new_map_ok_btn = new GLUI_Button(error_glui, "OK", ERROR_OK_BTN_ID, control_cb);
        }
    }
}