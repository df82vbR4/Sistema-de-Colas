# Proyecto: Sistema de Colas de Atención al Cliente
Este programa simula el funcionamiento de las colas en un banco. Permite gestionar clientes y transacciones, organizando y atendiendo solicitudes de diferentes tipos (VIP, Preferencial, Regular). El sistema no solo facilita la atención a los clientes, sino que también mantiene un historial de las transacciones atendidas, asegurando una gestión eficiente y ordenada en el entorno bancario, y simulando la experiencia real de atención al cliente centralizando el canal virtual y presencial.

## Características
1. **Gestión de Solicitudes**: Los clientes pueden presentar diferentes tipos de solicitudes (VIP, Preferencial, Regular).
2. **Atención Prioritaria**: Las solicitudes virtuales se gestionan en función de su prioridad, asegurando que las más urgentes sean atendidas primero.
3. **Historial de Solicitudes**: Se mantiene un registro detallado de todas las solicitudes virtuales atendidas, lo que permite un seguimiento efectivo.
4. **Consulta de Estado**: Los usuarios pueden consultar el estado de las solicitudes virtuales para mantenerse informados sobre su progreso.
5. **Carga desde Archivos**: El sistema permite cargar solicitudes virtuales y datos de clientes recibidos fuera del horario de atención desde archivos de texto, facilitando la integración de la información.
6. **Interacción en Tiempo Real**: Ofrece un menú interactivo que permite al usuario realizar diversas operaciones de manera sencilla y rápida.

## Estructura del Proyecto
1. **main.cpp**: Código fuente principal que contiene la lógica del sistema.
2. **clientes.txt**: Archivo de texto que contiene datos de clientes (cola en el banco) para pruebas.
3. **historial.txt**: Archivo de texto que almacena el historial de solicitudes atendidas.

## Estructuras de Datos Utilizadas
- **Cola (Queue)**:
  - Utilizada para manejar la cola de clientes que esperan ser atendidos presencialmente.
  - Permite el acceso al siguiente cliente en la fila siguiendo el principio FIFO (First In, First Out).
  - Funciones:
    - `push`: Agregar un cliente a la cola.
    - `pop`: Eliminar el cliente que está siendo atendido.

- **Cola de Prioridad (Priority Queue)**:
  - Utilizada para gestionar las solicitudes virtuales según su tipo y prioridad.
  - Permite atender las solicitudes en el orden correcto (VIP primero, seguido de Preferencial y Regular).
  - Funciones:
    - `push`: Agregar una nueva solicitud a la cola con su correspondiente prioridad.
    - `top`: Obtener la solicitud con la más alta prioridad sin eliminarla.
    - `pop`: Eliminar la solicitud de más alta prioridad de la cola.

- **Lista Enlazada (Linked List)**:
  - Utilizada para almacenar el historial de solicitudes atendidas de manera dinámica.
  - Permite un manejo dinámico de las solicitudes sin un tamaño fijo.
  - Iteración a través de la lista para mostrar el historial.
  - Funciones:
    - `insert`: Agregar una nueva solicitud atendida a la lista.

- **Hash Map (unordered_map)**:
  - Utilizado para asociar el ID de cada solicitud para almacenar y consultar el estado de las solicitudes de manera eficiente.
  - Permite un acceso rápido a la información del estado de una solicitud específica.
  - Funciones:
    - `insert`: Agregar un par clave-valor (ID de solicitud y estado).
    - `find`: Verificar el estado de una solicitud dada su ID.
    - `update`: Modificar el estado de una solicitud existente.

- **Estructura Solicitud**:
  - Representa cada solicitud realizada por un cliente.
  - Almacena información como el ID, nombre del cliente, tipo de solicitud, descripción y estado.

## Valor Añadido
El **Sistema de Colas de Atención al Cliente** incorpora diversas funcionalidades que añaden valor significativo a la experiencia de gestión de solicitudes y atención al cliente. A continuación, se detallan algunos de estos aspectos:

1. **Eficiencia en la Atención**:
   - El sistema está diseñado para optimizar el tiempo de atención a los clientes. Gracias a la implementación de colas y colas de prioridad, se garantiza que las solicitudes se manejen de manera rápida y organizada, minimizando el tiempo de espera y mejorando la satisfacción del cliente.

2. **Priorización Dinámica**:
   - Se utiliza una cola de prioridad para gestionar las solicitudes según su tipo (VIP, Preferencial, Regular). Esta priorización permite que las solicitudes más críticas sean atendidas primero, asegurando que los clientes que requieren atención inmediata reciban el servicio que necesitan sin demoras innecesarias.

3. **Mantenimiento de un Historial Detallado**:
   - El sistema guarda un registro completo de todas las solicitudes atendidas, lo que facilita la consulta de estados y el seguimiento de las transacciones. Esto no solo es útil para los clientes, sino que también permite a los empleados del banco revisar el historial y mejorar continuamente la calidad del servicio.

4. **Carga de Datos desde Archivos**:
   - La capacidad de cargar solicitudes y clientes desde archivos de texto simplifica la gestión del sistema, permitiendo una incorporación rápida de datos y una fácil integración con otros procesos administrativos.

5. **Interacción en Tiempo Real**:
   - El menú interactivo permite a los usuarios realizar operaciones de manera eficiente. Esto fomenta una experiencia de usuario fluida, donde se pueden agregar solicitudes, atender clientes y consultar estados sin complicaciones.

6. **Facilidad de Uso**:
   - La estructura del código y la organización de las funciones están diseñadas para ser intuitivas. Esto permite que tanto el personal del banco como los desarrolladores que trabajen en el sistema puedan entender y modificar el código con facilidad.

Estas características no solo hacen que el sistema sea funcional y eficiente, sino que también crean una base sólida para futuras mejoras y extensiones. Al integrar estas capacidades, el sistema ofrece una solución robusta para la atención al cliente en un entorno bancario, maximizando tanto la satisfacción del cliente como la productividad del personal.

## Requisitos o Dependencias
Este proyecto requiere un compilador de C++ que soporte el estándar C++11 o superior.

## Instalación
1. Clona el repositorio:
   ```bash
   git clone https://github.com/df82vbR4/Sistema-de-Colas.git
   cd Sistema-de-Colas
   
2. Compila el código:
   ```bash
   g++ -o sistema src/*.cpp
   
4. Ejecuta el programa:
   ```bash
   ./sistema

6. Interacción: Sigue las instrucciones del menú para agregar solicitudes, atender solicitudes, mostrar el historial, consultar estados y atender clientes.
   
7. Añadir los cambios a GitHub, hacer un commit y subir los cambios:
   ```bash
   git add .
   git commit -m "Commit_Descripción"
   git push origin main

## Instrucciones de Uso
Al ejecutar el programa, se mostrará un menú con las siguientes opciones:

1. Agregar Solicitud (Virtual)
2. Atender Solicitud (Virtual)
3. Mostrar Historial (Transacciones Virtuales)
4. Consultar Estado (Transacciones Virtuales)
5. Atender Cliente (Presencial)
6. Salir

## Funciones Principales
1. **agregarSolicitud**: Agrega una nueva solicitud al sistema (virtual). Ingresa el ID del cliente, nombre, tipo de solicitud y descripción.
2. **atenderSolicitud**: Atiende la siguiente solicitud (virtual) en espera (en la cola de prioridades).
3. **mostrarHistorial**: Muestra el historial de solicitudes atendidas (virtuales precargadas y añadidas recientemente).
4. **consultarEstado**: Proporciona el estado actual de una solicitud específica (virtual).
5. **AtenderCliente**: Atiende al siguiente cliente en la cola en el banco.
6. **cargarHistorialDesdeArchivo**: Carga solicitudes desde un archivo para el historial.
7. **cargarClientesDesdeArchivo**: Carga clientes desde un archivo y los agrega al sistema.

## Archivos de Datos
1. **clientes.txt**: Este archivo debe contener una lista de clientes, con cada línea en el siguiente formato: ID_Cliente Nombre_Cliente Tipo_Solicitud Descripción
   - Ejemplo:
     - 1 Juan VIP Reposición de Tarjeta
     - 2 Maria Preferencial Activación de Tarjeta
     - 3 Pedro Regular Reclamo de Cobro No Reconocido
      
2. **historial.txt**: Este archivo contiene un registro de las solicitudes atendidas, con el siguiente formato: ID_Solicitud ID_Cliente Nombre_Cliente Tipo_Solicitud Descripción Estado

   - Ejemplo: 
     - 1 1 Juan VIP Reposición de Tarjeta Pendiente
     - 2 2 Maria Preferencial Preferencial Activación de Tarjeta En Proceso
     - 3 3 Pedro Regular Reclamo de Cobro No Reconocido Atendida

## Limitaciones
Las solicitudes deben ser de un tipo válido (VIP, Preferencial, Regular).

## Enlaces
1. Repositorio GitHub: https://github.com/df82vbR4/Sistema-de-Colas.git
2. Video de Presentación: 

## Contribuciones
Si deseas contribuir a este proyecto, por favor sigue los siguientes pasos:
1. Haz un fork del repositorio.
2. Crea una nueva rama (git checkout -b feature/nueva-funcionalidad).
3. Realiza tus cambios y haz un commit (git commit -m 'Añadir nueva funcionalidad').
4. Sube tus cambios (git push origin feature/nueva-funcionalidad).
5. Abre un Pull Request.

## Autores
1. Camila Ballini
2. Yahna Chee
3. Adriana Morales
