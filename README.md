[<img src="https://javier.rodriguez.org.mx/itesm/2014/tecnologico-de-monterrey-blue.png" width=55% height=55%>](https://tec.mx/es)

# TC1004B_IoT

Implementación de internet de las cosas (Gpo 501)

## Proyecto Final - Prototipo de sensores

En este proyecto se presentan los procedimientos y documentación relativa al proyecto del bloque de Implementación del Internet de las Cosas (Gpo. 501) con el profesor Emmanuel Torres Ríos. La entrega de este proyecto se dió el **14 de noviembre de 2022**.

El objetivo de este reto es utilizar los conocimientos y habilidades necesarios para transmitir datos mediante el uso de sensores y actuadores en una aplicación domótica. Este sistema deberá estar basado en microcontroladores conectados a Internet, por lo que se tendrá que utilizar el concepto de Internet of Things. Como requisitos de este proyecto se encuentran:

- Sistema de dispositivos digitales basado en 5 microcontroladores interconectados en una red de datos para el intercambio de información.
- Uso de distintos protocolos (TCP, UDP, HTTP, MQTT, IFTTT o similares) de acuerdo con las distintas aplicaciones.
- Diseño e implementación de una arquitectura de Información en un servicio de alojamiento (Firebase).
- Servicio de alojamiento que permita la recopilación de datos, comunicación y generación de acciones.
- Programación, interconexión y puesta en operación de dispositivos.
- Análisis de requerimientos, planeación y administración del proceso de ejecución del sistema doméstico.







Para la elaboración del reto se te solicitará la implementación de un sistema interconectado de microcontroladores y funcionalidades con una especificación de referencia, sin embargo a lo largo de su implementación tu Asesor del Reto te solicitará diseñar algoritmos y servicios específicos que complementen la descripción de referencia, adecuando los requerimientos a mini-retos que se te plantearán resolver en tu implementación final; ejemplos de estos mini-retos pueden ser:

            Control de encendido y apagado de LEDs y luminarias
            Generación de señales de sincorización y reloj en la red domótica
            Incorporación de sensores adicionales
            Gestión avanzada de consumo eléctrico ("deepSleep") en los dispositivos de la red domótica





Si deseas acceder a la Wiki puedes hacer clic [aquí](https://github.com/A01736353/RetoFirebase/wiki).

## Integrantes del equipo

Los integrantes del equipo de este proyecto son:

- [**A01736171**](mailto:a01736171@tec.mx) Jesús Alejandro Gómez Bautista
- [**A01656774**](mailto:a01656774@tec.mx) César Guerra Martínez
- [**A01736353**](mailto:a01736353@tec.mx) Alejandro Daniel Moctezuma Cruz

## Elementos

Las fases documentadas en este proyecto son:

- [Creación de una **base de datos** en **Firebase**](https://github.com/A01736353/RetoFirebase/blob/main/1-BaseDatos.md)
- [Lectura y escritura de la **base de datos** usando **Python**](https://github.com/A01736353/RetoFirebase/blob/main/2-Python.md)
- [Lectura y escritura de la **base de datos** usando **Arduino IDE**](https://github.com/A01736353/RetoFirebase/blob/main/3-ArduinoIDE.md)
- [Lectura y escritura de la **base de datos** usando **AppInventor**](https://github.com/A01736353/RetoFirebase/blob/main/4-AppInventor.md)
- [Lectura de datos de **sensores** haciendo uso de los periféricos de un **ESP32**](https://github.com/A01736353/RetoFirebase/blob/main/5-SensoresESP32.md)


## Características del sistema

Los requisitos que se espera que se cumplan en este proyecto son:

- **Cinco sensores y variables** escribiendo datos en la base de datos.
- **Aplicación** con información de la base.
- **Programa en Python** que visualice la información almacenada.
- Cambiar el campo usuario por "Elemento mayor a 9" en caso de un elemento mayor a 9.
