
# Creación de la base de datos

Como primer paso de este proyecto final (o reto), se tuvo que llevar a cabo la creación de una base de datos en una plataforma que permitiese almacenar estos datos, hacer pruebas con ellos, y que tuviera compatibilidad con los sistemas que se utilizarían más adelante en las pruebas.

En este caso en específico, se optó por usar Firebase, la cual es un conjunto de herramientas para la creación de bases de datos y almacenamiento de datos 
por parte de Google. Se decidió tomar esta opción gracias a que:

- Es una plataforma **gratuita**, por lo que no es necesario pagar para acceder a sus servicios.
- Es una plataforma **compatible** con las herramientas posteriores (**Python, Arduino y AppInventor**)
- Tiene las **herramientas necesarias** para administrar la base de datos, su autenticación y transferencia de datos.

## Proceso de la creación de la base de datos

Como primer paso se accedió a [**Firebase**](https://firebase.google.com/?hl=es) y se inició sesión con la cuenta institucional.
Una vez realizado este paso, se hizo clic en "Comenzar" y "Crear un proyecto" respectivamente. Aquí se asignó un nombre del proyecto, un identificador único y se seleccionó como
organización de Google Cloud a itesm.mx. Se desactivó la opción de Google Analytics así como las funciones experimentales.

Una vez dentro del proyecto, 





Los integrantes del equipo de este proyecto son:

-  Jesús Alejandro Gómez Bautista
- [**A01656774**](mailto:a01656774@tec.mx) César Guerra Martínez
- [**A01736353**](mailto:a01736353@tec.mx) Alejandro Daniel Moctezuma Cruz

## Elementos

Las fases documentadas en este proyecto son:

- Creación de una **base de datos** en **Firebase**
- Lectura y escritura de la **base de datos** usando **Python**
- Lectura y escritura de la **base de datos** usando **Arduino IDE**
- Lectura y escritura de la **base de datos** usando **AppInventor**
- Lectura de datos de **sensores** haciendo uso de los periféricos de un **ESP32**

## Características del sistema

Los requisitos que se espera que se cumplan en este proyecto son:

- **Cinco sensores y variables** escribiendo datos en la base de datos.
- **Aplicación** con información de la base.
- **Programa en Python** que visualice la información almacenada.
- Cambiar el campo usuario por "Elemento mayor a 9" en caso de un elemento mayor a 9.
