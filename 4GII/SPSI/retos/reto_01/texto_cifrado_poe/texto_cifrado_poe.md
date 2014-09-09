Seguridad y Protección de Sistemas Informáticos
===============================================
4º Grado en Ingeniería Informática 2013/2014
--------------------------------------------


# Análisis del texto que venció a Poe
### Germán Martínez Maldonado
### José Manuel Castillo Pérez
### Pablo Sánchez Robles

En este documento vamos a analizar el texto encriptado que Edgar Allan Poe recibió de G. W. Kulp y no consiguió desencriptar. El texto es el siguiente:

```
    GE JEASGDXV,
ZIJ GL MW, LAAM, XZY ZMLWHFZEK EJLVDXW KWKE TX LBR ATGH LBMX AANU
BAI VSMUKKSS PWN VLWK AGH GNUMK WDLNZWEG JNBXVV OAEG ENWB ZWMGY
MO MLW WNBX MW AL PNFDCFPKH WZKEX HSSF XKIYAHUL. MK NUM YEXDM
WBXY SBC HV WYX PHWKGNAMCUK ?
```

Los únicos datos seguros son que usó una clave de sustitución polialfabética, pero no conozco el periodo ni las distintas funciones que utilizó para realizarlo, y que en el texto hay 16 errores, uno de ellos grave y 15 probablemente de la transcripción del tipógrafo. También sabemos que el idioma del texto original es el inglés por lo que tengo que utilizar su alfabeto para el descifrado.

Para realiza el análisis vamos a utilizar el método de Kasiski, éste método se basa en la búsqueda de fragmentos de texto repetidos en el mensaje cifrado, como no es demasiado improbable encontrar bigramas repetidos (probabilidad de 1/676) vamos a buscar trigramas cuya probabilidad de que sean fruto de la casualidad es 1/ 17576 lo cuál es muy poco probable.

Tras estudiar el texto podemos ver la repetición de tres trigramas distintos:

```
    GE JEASGDXV,
ZIJ GL MW, LAAM, XZY Z**MLW**HFZEK EJLVDXW KWKE TX LBR ATGH LBMX AANU
BAI VSMUKKSS PWN VLWK AGH G**NUM**K WDLNZWEG J**NBX**VV OAEG ENWB ZWMGY
MO **MLW** W**NBX** MW AL PNFDCFPKH WZKEX HSSF XKIYAHUL. MK **NUM** YEXDM
WBXY SBC HV WYX PHWKGNAMCUK ?
```

A continuación el método de Kasiski nos dice que tenemos que contar las distancias entre trigramas y calcular sus divisores, para así poder encontrar uno común que nos indique el número de funciones de transformación que se utilizaron.

* Las distancias y sus divisores son:
 * MLW = 91 {7,13,91}
 * NUM = 72 {2,3,4,6,8,9,12,18,24,36,72}
 * NBX = 24 {2,3,4,6,8,12,24}

Llegados a este punto vemos que tiene que haber algún error puesto que no hay ningún divisor común entre los de la distancia de MLW con los demás. El error puede venir del tipógrafo o del mismo Kulp pero la distancia entre los trigramas MLW no puede ser correcta ya sea por que se introdujo una letra de más entre ellos, se repitió el uso de alguna función o lo que es muy improbable la repetición de ese trigrama es fruto de la casualidad. Si por ejemplo la distancia fuera 90 en lugar de 91 ya sí existirían al menos 3 divisores comunes, pero no se puede guiar por un error por lo que se descarta usar ese trigrama para mi análisis.


Por lo tanto ahora dispongo de los siguientes divisores comunes: 2, 3, 4, 6, 12, 24.

Uno de los divisores antes nombrados ha de ser el periodo de repetición de las funciones. Para comprobar cuál de ellos es tenemos que hacerlo uno por uno utilizándolos todos. Para realizar esta tarea he desarrollado un pequeño programa que automatizará el proceso, el programa básicamente realiza las siguientes tareas:

1. Quitará caracteres especiales como son las comas, puntos,etc.
2. Eliminará los espacios entre palabra y los saltos de línea.
3. Dividirá el texto en partes, el número de partes vendrá dado por el divisor utilizado en cada vez. Una vez divido hará:
 * Calculará las frecuencias de cada letra en cada subdivisión.
 * Ordenará las frecuencias en un array de mayo a menor.
 * Sustituirá  las  letras  mas  frecuentes  de  cada  división  por  las  más frecuentes en el inglés ("e","t","a","o","i","n").
 * Unirá las distintas partes con las sustituciones de letras ya hechas e insertará caracteres especiales y espacios.

Comenzaremos con el divisor 2, las frecuencias de las letras de cada subdivisión son:

```
| K = 11 | W = 10 |
|:------:|:------:|
|  X = 8 |  E = 9 |
|  G = 7 |  M = 8 |
|  W = 7 |  A = 7 |
|  N = 7 |  S = 5 |
|  L = 6 |  L = 5 |
|  M = 6 |  V = 4 |
|  A = 5 |  X = 4 |
|  H = 5 |  B = 4 |
|  Z = 4 |  D = 3 |
|  B = 4 |  I = 3 |
|  U = 4 |  G = 3 |
|  J = 3 |  Y = 3 |
|  V = 3 |  N = 3 |
|  T = 2 |  H = 3 |
|  S = 2 |  Z = 3 |
|  Y = 2 |  P = 3 |
|  R = 1 |  F = 2 |
|  P = 1 |  U = 2 |
|  D = 1 |  K = 2 |
|  F = 1 |  C = 2 |
|        |  J = 1 |
|        |  O = 1 |
```

El texto con las letras sustituidas es :

```
    te JeAotDen,
ZIJ Gi ta, iAan, XZY ZtiWHFZeK eJiVDeW KWKe TX iBR aTGH iBte
aANU BAI VonUKKSo PWo niWK atH tNUtK WDioZaet JoBenV OAet
eoWB ZattY nO nia WoBe ta ai PoFDCFPKH aZKee HSoF XKIYaHUit KN
UtY eeDnW BXYo BCH na YeP HWKGoanCUK. ?
```

Analizando esta salida del programa no encontramos ninguna combinación de letras desencriptadas (en minúscula) que me pueda dar alguna pista sobre una palabra inglesa por lo que voy a pasar al siguiente divisor.

Con el divisor 3 las frecuencias serían:

```
| M = 7 | W = 7 | X = 6 |
|:-----:|:-----:|:-----:|
| E = 5 | A = 6 | L = 6 |
| V = 5 | E = 5 | K = 6 |
| X = 4 | D = 4 | W = 6 |
| K = 4 | Z = 4 | S = 5 |
| H = 4 | G = 4 | N = 5 |
| G = 3 | M = 4 | Y = 4 |
| A = 3 | K = 3 | M = 3 |
| W = 3 | B = 3 | A = 3 |
| B = 3 | U = 3 | G = 3 |
| U = 3 | H = 2 | J = 2 |
| N = 3 | L = 2 | T = 2 |
| Z = 2 | V = 2 | B = 2 |
| I = 2 | S = 2 | I = 1 |
| J = 1 | P = 2 | F = 1 |
| R = 1 | X = 2 | O = 1 |
| P = 1 | J = 1 | C = 1 |
| L = 1 | N = 1 | Z = 1 |
| F = 1 | O = 1 | D = 1 |
| C = 1 | Y = 1 | H = 1 |
|       | C = 1 |       |
```

El texto generado tras la sustitución de las letras es:

```
    nt JeeonaXt,
oIJ ie MW, eAeM, aon ZneWHFZtt eJetaXW Kaot Ta LBR eTnH eBnX
AeiU BAI VoMUtoSo PWi tLao eGi iiUnt WaeNoaei JNBXtV OAtG eNaB
oaMin MO MLW aNBX MW AL PiFaCFPti WZotX iSoF XtIYAiUeM Ki Unn
eXDMW BaYo BCH tW naP HWKGNeMCUt. ?
```

En este caso tampoco consigo descrifrar ninguna palabra en inglés en este texto. Con el divisor 4 las frecuencias serían:

```
| W = 5 | E = 4 | K = 8 | E = 6 |
|:-----:|:-----:|:-----:|:-----:|
| G = 4 | L = 4 | L = 4 | W = 6 |
| X = 4 | X = 4 | A = 4 | M = 4 |
| U = 4 | M = 4 | X = 4 | I = 3 |
| N = 4 | W = 4 | M = 4 | N = 3 |
| H = 3 | A = 4 | G = 3 | S = 3 |
| K = 3 | B = 3 | Z = 3 | V = 3 |
| V = 3 | S = 2 | J = 2 | A = 2 |
| B = 3 | F = 2 | S = 2 | G = 2 |
| M = 2 | D = 2 | H = 2 | U = 2 |
| L = 2 | K = 2 | T = 1 | P = 2 |
| A = 1 | H = 2 | B = 1 | C = 2 |
| J = 1 | Z = 2 | N = 1 | D = 1 |
| Z = 1 | Y = 2 | W = 1 | Y = 1 |
| T = 1 | V = 1 | D = 1 | L = 1 |
| R = 1 | G = 1 | Y = 1 | B = 1 |
| P = 1 | O = 1 |       | Z = 1 |
| D = 1 | P = 1 |       | J = 1 |
| F = 1 | C = 1 |       | O = 1 |
| Y = 1 |       |       | H = 1 |
```

El texto con las letras sustituidas es:

```
    eE JEASiDtV,
naJ Ge tW, etAM, tnY ZaeeiFnEn EJLVDae noKE Tt eBR iTGi eBtt itoa
nta VSoUnKSi PoN nLoK AeH ioaaK eDeNZWEi JonanV OtEe ENeB
ZWteY oO MeW eona tW ie PoFDCFPKH WZKEt HSiF tKaYiHULa Ko
aaY EtDoe BtYi BCH nW YaP ioKGoioCaK. ?
```

Todavía no se puede descifrar ninguna palabra. Con el divisor 6 las frecuencias serían:

```
| K = 3 | E = 5 | X = 6 | E = 5 | W = 5 | S = 5 |
|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
| B = 3 | A = 4 | K = 5 | V = 4 | K = 3 | L = 4 |
| U = 3 | M = 3 | L = 3 | M = 4 | G = 3 | W = 4 |
| M = 3 | B = 3 | M = 3 | X = 3 | A = 2 | Y = 3 |
| A = 2 | D = 2 | N = 2 | W = 3 | Z = 2 | N = 2 |
| N = 2 | U = 2 | G = 2 | H = 3 | H = 2 | A = 2 |
| G = 1 | W = 2 | J = 1 | I = 2 | L = 2 | I = 1 |
| J = 1 | P = 2 | T = 1 | G = 1 | V = 2 | F = 1 |
| Z = 1 | G = 1 | A = 1 | A = 1 | S = 2 | B = 1 |
| V = 1 | Z = 1 | W = 1 | K = 1 | D = 2 | J = 1 |
| R = 1 | O = 1 | Y = 1 | L = 1 | Y = 2 | O = 1 |
| P = 1 | X = 1 | B = 1 | F = 1 | J = 1 | C = 1 |
| L = 1 | C = 1 | H = 1 | C = 1 | N = 1 | Z = 1 |
| F = 1 |       |       |       | X = 1 | D = 1 |
| H = 1 |       |       |       | U = 1 | G = 1 |
| X = 1 |       |       |       |       | K = 1 |
```

El texto con las letras sustituidas es:

```
    nE nEaSnoXe,
onJ Gt tW, eoea, aoa ZttoiFZEe EJeVoXo etKE Ta nBR eTGi eetX Aaot
aAn VSaieKSS Pno entK eii totte oDeiZWEt JiaXeV OoEi ENte ZWtta aO
aLW tiaX tW iL PoFDCFPei WZKEX iSSF XenYiHitt eo ttY EXDan BaYS
eCH eW aXP HoeGieaCUK. ?
```

Todavía sin sacar ninguna palabra en claro. Con el divisor 12 las frecuencias serían:

```| U = 3 | M = 3 | X = 3 | M = 3 | W = 4 | L = 3 | K = 3 | E = 3 | X = 3 | X = 3 | S = 2 | N = 3 |
|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
| N = 3 | B = 3 | K = 3 | E = 2 | H = 2 | S = 2 | M = 3 | A = 2 | M = 2 | E = 3 | K = 2 | S = 3 |
| B = 2 | A = 2 | J = 1 | W = 2 | V = 2 | Y = 2 | A = 2 | U = 2 | K = 2 | H = 2 | Z = 1 | I = 1 |
| G = 1 | E = 1 | L = 1 | I = 2 | A = 1 | A = 2 | G = 1 | P = 2 | G = 2 | V = 1 | J = 1 | Y = 1 |
| J = 1 | G = 1 | T = 1 | V = 2 | K = 1 | F = 1 | Z = 1 | D = 1 | T = 1 | A = 1 | L = 1 | L = 1 |
| Z = 1 | D = 1 | A = 1 | G = 1 | L = 1 | W = 1 | B = 1 | M = 1 | W = 1 | K = 1 | A = 1 | B = 1 |
| V = 1 | W = 1 | N = 1 | H = 1 | D = 1 | O = 1 | N = 1 | Z = 1 | N = 1 | L = 1 | G = 1 | J = 1 |
| R = 1 | Z = 1 | W = 1 | C = 0 | G = 1 | Z = 1 | L = 1 | O = 1 | L = 1 | F = 1 | N = 1 | W = 1 |
| P = 1 | P = 1 | Y = 1 |       | Y = 1 | D = 1 | H = 1 | W = 0 | B = 1 | M = 1 | W = 1 | C = 1 |
| F = 1 | X = 1 | H = 1 |       | X = 1 | K = 0 | X = 0 |       | H = 0 | W = 0 | D = 1 | G = 0 |
|       | C = 0 | M = 0 |       | U = 0 |       |       |       |       |       | Y = 0 |       |
```

El texto con las letras sustituidas es:

```
    ee ateteoXe,
aao oe MW, Latt, Xae iMeatooEa teoniXa oiKE oX oiR aoit LiiX oiNU **tie**
attaaiSt Pnn oiiK tea nNUMt anLnnitn nttXoa naEe tNWa ZWMGa tO tnW
WttX MW eL enFDCFPtn WZKEX aStF XteYeHaLM tN UMY tXDtW BXYt
aCH oW aXe HWtGtaMCUK. ?
```

En este caso parece que se ve algo más, la palabra resaltada podría ser el artículo **“the”** cambiando la **“i”** por la **“h”**, por lo que ahora habría que averiguar qué funciones se utilizan en las tres letras de dicha palabra para hacer la transformación. Esas tres letras están cifradas con las funciones de encriptado f2, f3, f4, haciendo un calculo rápido de las distancias entre las letras cifradas y las descifradas vemos que son : f2 = 18, f3 = 7, f4 = -4.

Tras hacer el cambio con estas distancias en las letras de esas funciones el texto nos queda:

```
    Gw qaASGDXV,
ZIJ ys iW, LAAM, XZY ZessHFZEK EJLVves KWKE TX LBR sacH LBMX
AANU **the** VSMUKKSS PourLWK AGH GNUer sDLNZWEG JNterV OAEG
ENWB rdiGY MO MLW WNte iW AL PNFDCFhrd WZKEX HSSF
**preYAHUL**. MK NUe faXDM WBXY **SBu or** WYX PHWKGNstyUK ?.
```

Como vemos ya se han formado algunas palabras más, aunque algunas de las sustituciones forman palabras inexistentes, puede ser que sean de los 16 fallos que el texto tiene.


Una de las subrayadas es **“SBu”** seguida de la palabra **“or”**, buscando palabras de tres letras en inglés acabadas en u encontramos muchas pero probaremos con la mas común de todas que sería **“you”**, lo cuál nos da otras posibles 2 funciones de transformación, la de f1 y la de f12 cuyas distancias son f1 = 13, f12 = 15.

Desencriptando con esas nuevas dos funciones el texto queda:

```
    tw qaASGDXV,
**Zow** ys iW, LAAM, XZe messHFZEK EJrives KWKE TX **Lhe** sacH LBMX
AAth the VSMUKKSy courLWK AGH Gther sDLNZWEG paterV OAEG
ENco rdiGY MO MLW cate iW AL PNFDishrd WZKEX HSys preYAHUL.
MK the faXDM WBXY you or WYX PHWKmastyUK ?.
```

Con esta desencriptación vemos como vuelven a aparecer palabras nuevas ya legibles, lo cuál nos indica que vamos por buen camino, las dos palabras subrayadas en este paso son fácilmente traducibles, la  primera claramente es **“How”** y la segunda vuelve a ser **“The”**, por lo que tenemos otra función mas y su respectiva distancia(las dos letras, L y Z pertenecen a la misma función): f11 = 8.

Con la nueva función descubierta el texto quedaría:

```
    tw qaASGDXV,
how ys **iW**, LAAM, **Xhe** messHFZEK **Errives** KWKE TX the sacH LBMX
Aith the VSMUKKay courLWK AGH other sDLNZWEo paterV OAEG Evco
rdiGY MO MLe cate iW AL PNFlishrd WZKEX Hays preYAHUL. Ms the
faXDM WBXg you or WYX PHWsmastyUK ?.

Tras esta nueva función vemos tres palabras más, las dos primeras son **“iW”** y **“Xhe”**, la primera de ellas podría ser **“it”** puesto que la frase comienza con **“How”** y podría ser **“How is it”**, aunque la segunda palabra de esa frase esté mal transcrita, **“ys”** puede ser uno de los 16 errores. La segunda palabra subrayada es claramente es **“the”** y la última podría ser **“Arrives”**. Con esto vamos a descubrir las nuevas funciones, que son: f5 = 23 y f10 = 22.

El texto generado es:

```
    tw qaxSGDXr,
how ys it, LAAM, the **messeFZEK** arrives hWKE Tt the sace LBMX with
the sSMUKgay couriWK AGd other saLNZWao paters OAEG avco rdidY
MO Mhe cate it AL PNblishrd tZKEX days prevAHUL. is the fauDM WBtg
you or tYX PHssmastyrK ?.
```

Buscando por internet palabras que comiencen con **“messe”** (la palabra subrayada) y con nueve letras encuentramos 3 palabras messelite, messenger y messenian, probamos la más común de ellas, "messenger". Con esta palabra encontramos las 4 funciones que faltan, en este caso serían: f6 = 8 , f7 = 7, f8 = 0 , f9 = 7.

El texto ya descodificado totalmente sin la corrección de los errores cometidos por Kulp o el transcriptor es:

```
    **tw** **qa**xander,
how **y**s it, that, the messenger arrives here at the sa**c**e time with the
satur**g**ay courier and other satu**z**da**o** pa**t**ers when a**v**co rdid**g** to the **c**ate
it is publish**r**d three days previous. is the fault wit**g** you or t**g**e
possmast**y**rs ?.
```

Como se puede apreciar los caracteres subrayados son los 16 errores cometidos en el texto ya sea por parte de Kulp o de los transcriptores de la revista Allexander, solucionando esos errores el texto quedará:

```
    Mr Allexander,
How is it, the messenger arrives at the same time with the saturday
courier and other saturday papers when according to the date it is
published three days previous. Is the fault with you or the
possmaster?.
```

Traducido al español el texto significa algo así como:

```
    Sr Allexander,
¿Cómo es posible que el mensajero llegue al mismo tiempo con el correo
del sábado y otros papeles del sábado cuando de acuerdo con la fecha en
que se publica es de tres días antes?. ¿El error es suyo o del 
cartero?.
```

Como conclusión queda decir que sin un sistema automatizado para la comprobación de distintas combinaciones de letras se hace bastante difícil el descifrado de éste texto por los errores que contiene puesto que si se hace a mano las pruebas serían muy lentas y el no encontrar cadenas legibles al principio desalentaría a la persona que tratara de descifrarlo dándole la sensación que tuvo Poe de que el texto es una combinación de caracteres aleatorios sin conexión ni sentido.
