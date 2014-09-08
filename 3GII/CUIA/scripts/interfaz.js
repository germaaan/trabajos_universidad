/**
 * @author German Martinez Maldonado
 * @author Pablo Sanchez Robles
 */

var xInicial : float = (Screen.width / 2) - 100;
var yInicial : float = (Screen.heith / 2) - 50;
var ancho : float = 200;
var alto : float = 100;
var preguntas = new Array();
var respuestas = new Array();
preguntas[0] = new Array("¿Capital de Italia?", "Madrid", "París", "Londres", "Roma");
preguntas[1] = new Array("¿Cuál es la concentración informática del País Vasco?", "Euskadi Party", "Campus Party", "Salvis Party", "Euskal Party");
preguntas[2] = new Array("¿Quién esta al mando del ejercito en España?", "El rey", "el papa", "La mama", "El presidente");
respuestas = new Array(4, 4, 1);

function OnGui() {

    var rand = Random.Range(0, 3);

    GUI.Label(Rect(xInicial, yInicial, ancho, alto), preguntas[rand][0]);
    if (GUI.Button(Rect(xInicial, yInicial + 100, ancho, alto), preguntas[rand][1]))
    {
        if (respuestas[rand] == 1) {
            Application.LoadLevel("Acierto");
        }
        else {
            Application.LoadLevel("Error");
        }
    }
    else if (GUI.Button(Rect(xInicial, yInicial + 100, ancho, alto), preguntas[rand][2]))
    {
        if (respuestas[rand] == 2) {
            Application.LoadLevel("Acierto");
        }
        else {
            Application.LoadLevel("Error");
        }
    }
    else if (GUI.Button(Rect(xInicial, yInicial + 100, ancho, alto), preguntas[rand][3]))
    {
        if (respuestas[rand] == 3) {
            Application.LoadLevel("Acierto");
        }
        else {
            Application.LoadLevel("Error");
        }
    }
    else if (GUI.Button(Rect(xInicial, yInicial + 100, ancho, alto), preguntas[rand][4]))
    {
        if (respuestas[rand] == 4) {
            Application.LoadLevel("Acierto");
        }
        else {
            Application.LoadLevel("Error");
        }
    }

}