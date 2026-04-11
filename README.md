# Meteo, estación metereológica básica

Programada en una tarde, Meteo es un buen proyecto para acercarse a las placas de desarrollo y al entorno de Visual Studio Code.

---

## 🚀 Introduccion

La idea es programar una estación metereologica desde ***Visual Studio Code***
que nos sirva para comenzar a relacionarnos con ese entorno de trabajo y la programacion desde el entorno arduino, por lo que realmente este progroma no representa una novedad en lo que a código se refiere


[![Meteo: Estación Meteorológica Básica](https://img.youtube.com/vi/L3shunAluEo/0.jpg)](https://www.youtube.com/watch?v=L3shunAluEo)



## 📋 Características

La información metereolólogica se extrae de [openweathermap.org](https://home.openweathermap.org) por lo que necesitaras una cuenta que te permita acceder a la clave api, para que tu programa pueda optener la informacion necesario. Por lo demas es muy básica, tiene iconos para cuatro estados del tiempo y nos muestra la ciudad, la temperatura, la humedad, el estado del tiempo y un icono representativo de ese estado.

## 🛠️ Tecnologías utilizadas

En este apartado tampoco vamos a sorprender a nadie, son todos elementos sencillos muy faciles de conseguir. El reto está un poco en hacerlo desde Visual Studio Code para alguien que nunca ha usado este software.

* Una placa de desarrollo ESP8266 Wemos D1 Mini
* Una pantalla oled SSD1306 I2c
* Una protoboard pequeña
* Cuatro cables de conexion
* Visual Studio Code

## 📦 Instalación

La instalación es sencilla nos descargamos los archivos de este repositorio e instalamos [Visual Studio Code](https://code.visualstudio.com/) para configurarlo. En este punto tengo que recalcar que todo el trabajo aquí expuesto es para realizarlo desde Linux, en concreto Ubuntu y derivados como es mi caso con [Linux Mint](https://linuxmint.com/), asi que descargo el .deb que es el que me toca.

Tambien dispondreis del archivo platformio.ini absolutamente necesario para la configuración y la instalacion de bibliotecas. Estarán también disponibles unas instrucciones que sirven como guia para tener el entorno operativo.

## 📄 Licencia

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

## 💬 Contacto

<a href="https://tally.so/r/D4JADZ" target="_blank">
  <img src="https://img.shields.io/badge/CONTACT FORM-brightgreen?style=flat-square" alt="Contacto">
</a>

## 👨‍💻 Autor

- [@Binarybiker](https://github.com/Binarybiker)
- [www.binarybiker.men](https://www.binarybiker.men)

NOTA: Este es un programa de uso no comercial y educativo. Se entrega "tal cual", sin garantías de funcionamiento ni soporte oficial. El autor no se hace responsable de efectos directos o indirectos del software, ni de posibles daños físicos en la placa, componentes electrónicos o periféricos derivados de la carga de firmware o el uso del código. El usuario asume toda la responsabilidad al ejecutarlo.
