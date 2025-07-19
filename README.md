# Sistema de Simulación de Comunicación Celular

Este proyecto es una simulación de un sistema de comunicación celular que modela las interacciones entre clientes, operadores de telefonía y su facturación. El sistema permite registrar clientes y operadores, simular el uso de servicios como llamadas, mensajes y conexión a internet, y gestionar la facturación de cada usuario, aplicando las lógicas de costos y descuentos específicas de cada operador.

## Visión General del Sistema

El corazón de esta simulación reside en la interacción de tres entidades principales:

**Clientes (Customer):** Representan a los usuarios del sistema de telefonía. Cada cliente tiene sus datos personales (ID, nombre, edad), está asociado a un operador específico y cuenta con su propia factura. Los clientes pueden realizar llamadas, enviar mensajes y usar internet.

**Operadores (Operator):** Son las compañías que proveen los servicios de comunicación. Existen dos tipos especializados de operadores, cada uno con su propia política de precios y descuentos:

- **VoxOperator:** Especializado en llamadas y mensajes, ofreciendo descuentos basados en la edad del cliente o si la comunicación es entre usuarios del mismo operador.

- **InternetOperator:** Enfocado en el uso de datos, con una franquicia de datos gratuita y descuentos en llamadas y mensajes según la cantidad utilizada.

**Facturas (Bill):** Cada cliente tiene una factura asociada que gestiona su límite de crédito, la deuda actual y el historial de pagos. La factura se encarga de verificar si un cargo puede ser aplicado y de procesar los pagos realizados por el cliente.

## Funcionalidades Clave

El sistema simula las siguientes operaciones principales:

**Creación y Gestión de Clientes:** Se pueden registrar nuevos clientes en el sistema, asignándoles un operador y un límite de crédito inicial para su factura.

**Creación y Gestión de Operadores:** Se pueden definir diferentes operadores con sus tarifas y descuentos específicos para llamadas, mensajes y uso de internet.

**Interacciones de Comunicación:**

- **Llamadas:** Un cliente puede llamar a otro, y el costo se calcula según las tarifas de su operador, aplicando descuentos si corresponden (por ejemplo, por edad o por duración).

- **Mensajes:** Los clientes pueden enviarse mensajes, con costos y descuentos que pueden depender del operador del remitente y del destinatario.

- **Uso de Internet:** Los clientes pueden consumir datos, y el sistema calcula el costo considerando las políticas de su operador (por ejemplo, datos gratuitos o tarifas por GB).

**Gestión de Facturación:**

- **Cargos Automáticos:** Los costos de las llamadas, mensajes y uso de internet se añaden automáticamente a la factura del cliente, siempre que no excedan su límite de crédito.

- **Pagos:** Los clientes pueden realizar pagos para reducir su deuda pendiente.

- **Modificación del Límite de Crédito:** Los clientes pueden solicitar un cambio en su límite de crédito, sujeto a ciertas condiciones (como la deuda actual).

- **Cambio de Operador:** Un cliente puede cambiar de operador, transfiriendo su servicio a una nueva compañía.

## Funcionamiento General

La simulación se ejecuta leyendo una serie de operaciones desde un archivo de entrada. Estas operaciones describen eventos como la creación de nuevos clientes y operadores, llamadas, mensajes, uso de internet, pagos de facturas o cambios de operador. El sistema procesa cada evento, actualizando las estadísticas de los clientes y operadores, y finalmente, genera un informe detallado en un archivo de salida.

El informe de salida incluye:

- Un resumen del rendimiento de cada operador (tiempo total de llamadas gestionado, mensajes enviados y datos consumidos).

- Un desglose de la situación financiera de cada cliente (dinero total gastado y deuda actual).

- Identificación de los clientes más activos en términos de llamadas, mensajes e internet, mostrando sus respectivos consumos.

Este proyecto ofrece una visión funcional de cómo se gestionan los servicios y la facturación en un sistema de comunicación celular básico, demostrando la aplicación de principios de programación orientada a objetos para modelar entidades complejas y sus interacciones.

## Cómo Ejecutar el Código

Para compilar y ejecutar este proyecto, sigue los siguientes pasos:

### 1. Compilación

Asegurarse de tener un compilador C++11 instalado en tu sistema. Navega hasta el directorio raíz del proyecto donde se encuentra `main.cpp` y los archivos `.h`, y ejecuta el siguiente comando en la terminal:

`g++ -std=c++11 main.cpp -o app`

### 2. Ejecución

Una vez compilado, puedes ejecutar el programa proporcionando los nombres de un archivo de entrada y un archivo de salida como argumentos:

`./app input_file.txt output_file.txt`

- **input_file.txt:** Es el archivo de entrada con las operaciones a simular. Puedes usar los archivos **input0.txt**, **input1.txt**, etc., para probar el sistema.

- **output_file.txt:** Es el archivo donde se escribirán los resultados de la simulación.

### Ejemplo de Ejecución

`./app input0.txt my_simulation_output.txt`

Con los archivos de salida proporcionados (ej. **output0.txt**, **output1.txt**, **output2.txt**), puedes verificar que tu implementación funciona correctamente al comparar los resultados generados por tu programa con los resultados esperados.

## Créditos

Este proyecto fue desarrollado como parte de la materia de Programación Orientada a Objetos del Tecnológico de Monterrey.
