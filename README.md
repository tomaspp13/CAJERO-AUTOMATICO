Sistema de Gestión de Cuentas Bancarias 🏦
Simulación de un sistema bancario desarrollado en C++. Permite gestionar cuentas de clientes mediante una lista enlazada, con operaciones de alta, búsqueda, retiro de dinero y eliminación de cuentas.
¿Cómo funciona?
El programa presenta un menú interactivo donde el usuario puede administrar cuentas bancarias. Cada cuenta almacena el nombre del titular, DNI, código de cuenta y saldo. Las cuentas se gestionan internamente con una lista enlazada simple.
Estructura del proyecto

CUENTA — Nodo que representa una cuenta bancaria con sus datos y saldo.
LISTA — Clase principal que gestiona la lista de cuentas y todas las operaciones sobre ellas.

Funcionalidades

Alta de cuenta — Registra una nueva cuenta con nombre, DNI, código y saldo inicial.
Búsqueda de cuenta — Busca una cuenta por DNI y código, mostrando nombre y saldo.
Retiro de dinero — Descuenta un monto ingresado del saldo de la cuenta.
Eliminación de cuenta — Elimina una cuenta de la lista buscándola por DNI.
Listado general — Muestra todas las cuentas registradas con su saldo.

Menú de opciones
1 - Ingresar cuenta
2 - Buscar cuenta
3 - Retirar dinero
4 - Eliminar cuenta
0 - Salir
Tecnologías

C++
Listas enlazadas
Programación orientada a objetos
