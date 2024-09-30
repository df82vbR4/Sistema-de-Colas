# Sistema de Colas de Atención al Cliente

Este proyecto simula el funcionamiento de las colas en un banco, gestionando clientes y transacciones.

## Estructuras de Datos Utilizados
- Listas Enlazadas
- Colas

## Requisitos Previos

Antes de ejecutar el proyecto, asegúrate de tener instalado lo siguiente:
- GCC (GNU COmpiler Collection)
- Git
- Visual Studio Code

## Cómo Ejecutar el Proyecto

1. Clona el repositorio:
   ```bash
   git clone https://github.com/df82vbR4/Sistema-de-Colas.git
   cd Sistema-de-Colas
2. Compila el código:
   g++ -o sistema src/*.cpp
3. Ejecuta el programa:
   ./sistema

### Optimización


#### Valor añadido


##### Notas adicionales

**Uso del Programa**
Al ejecutar el programa, verás un menú con las siguientes opciones:
1. Añadir un cliente a la cola.
2. Atender al siguiente cliente.
3. Mostrar el estado de la cola.
4. Salir.

**Añadir un Cliente**
Para añadir un cliente, selecciona la opción 1 e ingresa los datos solicitados (nombre, número de cédula, número de cuenta, etc.).

**Atender al Siguiente Cliente**
Selecciona la opción 2 para atender al siguiente cliente en la cola. El programa mostrará los detalles del cliente atendido y lo eliminará de la cola.

**Mostrar el Estado de la Cola**
Selecciona la opción 3 para ver una lista de todos los clientes actualmente en la cola.

**Salir**
Selecciona la opción 4 para salir del programa.

**Documentación**
* Manual de Usuario: docs/
* Diagrama UML: docs/UML.png

**Subir los Cambios a GitHub**
1. Añadir los cambios:
   git add .
2. Hacer un commit:
   git commit -m "Initial commit with project structure and README"
3. Subir los cambios:
   git push origin main

**Contribuciones**
Si deseas contribuir a este proyecto, por favor sigue los siguientes pasos:
1. Haz un fork del repositorio.
2. Crea una nueva rama (git checkout -b feature/nueva-funcionalidad).
3. Realiza tus cambios y haz un commit (git commit -m 'Añadir nueva funcionalidad').
4. Sube tus cambios (git push origin feature/nueva-funcionalidad).
5. Abre un Pull Request.

**Licencia**
Este proyecto está bajo la Licencia MIT. Para más detalles, consulta el archivo LICENSE.
