
# Lectura y escritura en la base de datos usando Arduino

Como primer entorno de desarrollo integrado se encuentra Arduino, con el que se buscaba transmitir un _ a la base de datos de Firebase. Para ello, se hizo uso de un ESP32, desarrollado por Unit Electronics, que sería conectado a un puerto USB de la computadora. A continuación se elistan los pasos realizados para llevar a cabo este proceso.

## Instalación del IDE de Arduino

Para subir una aplicación (o código de transferencia de datos en nuestro caso) se requería primero de instalar Arduino IDE. 
Para ello, nos dirigimos a la página oficial de [**Arduino**](https://www.arduino.cc/en/software) en su apartado de software, y descargamos el instalador correspondiente a 
nuestro sistema operativo, en este caso Windows 10. En este apartado, se pregunta además si deseamos donar para la contribución de Arduino.

Se ejecuta el archivo .exe, sin modificar los parámetros de instalación predeterminados. Se da clic en el botón de "Siguiente" en cada paso, hasta llegar la finalización de la instalación. Una vez terminada esta, se ejecuta el programa de Arduino IDE.

## Configuración del Arduino

Una vez dentro de la aplicación de Arduino IDE, nos dirigimos a la pestaña de Preferencias. En la casilla "Gestor de URLs Adicionales de Tarjetas", es necesario colocar la dirección URL de la tarjeta ESP32, en nuestro caso la desarrollada por Electronic Units. Por ello, colocamos la siguiente dirección: https://dl.espressif.com/dl/package_esp32_index.json. 

Siguiente a esto, instalamos las librerías correspondientes al ESP32. Para la situación actual, instaló la librería _, por _.

## Codigo utilizado

Una vez instaladas las librerías, se necesitó de un código para transmitir los datos por medio del IoT a la base de datos de Firebase. Para ello ocupamos el siguiente código:
