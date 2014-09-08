/**
 * @author German Martinez Maldonado
 * @author Pablo Sanchez Robles
 */

#pragma strict
        
                function OnGui()
                {
                    GUI.Label(Rect((Screen.width / 2) - 100, (Screen.height / 2) - 50, 200, 100), "Ha acertado");
                    if (GUI.Button(Rect((Screen.width / 2) - 100, (Screen.height / 2) + 50, 200, 100), "volver al juego"))
                    {
                        Application.LoadLevel("juego");
                    }
                }