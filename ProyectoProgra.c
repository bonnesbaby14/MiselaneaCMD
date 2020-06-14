#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Este proyecto tiene como propósito principal llevar el control de un consultorio, teniendo dos structs
// Uno el cual es de las consultas y el otro de los clientes.
// Miguel Angel Luis Espinoza y Gabriel Alfonso Rodriguez Angeles

typedef struct Clientes {
  int numeroCliente;
  char nombre[50];
  char apellidos[50];
  int telefono;
  int edad;
}
clientes;

typedef struct Consulta {
  int numeroConsulta;
  char nombre[50];
  char apellidos[50];
  char fecha[50];
  char hora[10];
}
consultas;

clientes cliente[20];

consultas consulta[20];

int auxCl = 0, auxCon = 0, flagCli = 0, flagCon = 0, i, arreglo;

void menuClientes();
void registrarClientes(clientes cliente[], int * auxCl);
void buscarClientes();
void eliminarClientes();
void mostrarClientes();
void cargando();

void menuConsultas();
void registrarConsulta(consultas consulta[], int * auxCon);
void buscarConsulta();
void eliminarConsulta();
void mostrarConsulta();

int main(int argc, char * argv[]) {
pantallaCarga();
  int opc;

  do {
  	system("cls");
    printf("--- Menu Principal --- \n");
    printf("[1] Clientes \n");
    printf("[2] Consultas \n");
    printf("[3] Salir \n");
    scanf("%i", & opc);
    switch (opc) {
    case 1:
    	system("cls");
      menuClientes();
      break;

    case 2:
    	system("cls");
      menuConsultas();
      break;
    }

  } while (opc != 3);
  printf("Saliendo del programa ");
  
  cargando();
  return 0;
}

void menuClientes() {
  int opc;
  do {
  	system("cls");
    printf("--- Menu Clientes --- \n");
    printf("[1] Registro \n");
    printf("[2] Busqueda \n");
    printf("[3] Eliminacion \n");
    printf("[4] Consulta de informacion \n");
    printf("[5] Volver al menu \n");
    scanf("%i", & opc);
    switch (opc) {
    case 1:
    	system("cls");
      registrarClientes(cliente, & auxCl);
      break;

    case 2:
    	system("cls");
      buscarClientes();
      break;

    case 3:
    	system("cls");
      eliminarClientes();
      break;

    case 4:
    	system("cls");
      mostrarClientes();
      break;
    }

  } while (opc != 5);
}

void registrarClientes(clientes cliente[], int * auxCl) {
  if ( * auxCl < 20) {

    printf("Ingrese el numero de cliente: \n");
    scanf("%i", & cliente[ * auxCl].numeroCliente);

    printf("Ingrese el nombre del cliente: \n");
    fflush(stdin);
    gets(cliente[ * auxCl].nombre);

    printf("Ingrese el apellido del cliente: \n");
    fflush(stdin);
    gets(cliente[ * auxCl].apellidos);

    printf("Ingresa la edad del cliente: \n");
    scanf("%i", & cliente[ * auxCl].edad);

    printf("Ingrese el telefono: \n");
    scanf("%i", & cliente[ * auxCl].telefono);

    * auxCl = * auxCl + 1;

  } else {
    printf("Ya no se pueden agregar más clientes \n");
    getch();
  }
}

void buscarClientes() {
  int numero, subopc;
  flagCli = 0;

  printf("Ingrese el numero del cliente: \n");
  scanf("%i", & numero);
  for (i = 0; i <= auxCl - 1; i++) {
    if (numero == cliente[i].numeroCliente) {
      arreglo = i;
      flagCli = 1;
      do {
      	
        printf("--- Submenu Clientes cambios --- \n");
        printf("[1] Nombre \n");
        printf("[2] Apellidos \n");
        printf("[3] Edad \n");
        printf("[4] Telefono \n");
        printf("[5] Regresar al menu de Clientes \n");
        scanf("%i", & subopc);
        switch (subopc) {
        case 1:
          printf("Anterior nombre: %s \n", cliente[arreglo].nombre);
          printf("Nuevo nombre: \n");
          fflush(stdin);
          gets(cliente[arreglo].nombre);
          break;
        case 2:
          printf("Anteriores apellidos: %s \n", cliente[arreglo].apellidos);
          printf("Nuevos apellidos: \n");
          fflush(stdin);
          gets(cliente[arreglo].apellidos);
          break;
        case 3:
          printf("Anterior edad: %i \n", cliente[arreglo].edad);
          printf("Nueva edad: \n");
          scanf("%i", & cliente[arreglo].edad);
          break;
        case 4:
          printf("Anterior telefono: %i \n", cliente[arreglo].telefono);
          printf("Nuevo telefono: \n");
          scanf("%i", & cliente[arreglo].telefono);
          break;
        }
      } while (subopc != 5);
    }
  }
  if (flagCli == 0) {
    printf("--- No se encontro al cliente --- \n");
    getch();
  }
}

void eliminarClientes() {
  int numero, opc;
  flagCli = 0;

  printf("Ingrese el numero del cliente:\n");
  scanf("%d", &numero);

  for (i = 0; i <= auxCl - 1; i++) {
  	  
    if (numero == cliente[i].numeroCliente) {
    
      arreglo = i;
      flagCli = 1;
    
      printf("Numero: %d \n", cliente[arreglo].numeroCliente);
      printf("Nombre: %s \n", cliente[arreglo].nombre);
      printf("Apellidos: %s \n", cliente[arreglo].apellidos);
      printf("Edad: %i \n", cliente[arreglo].edad);
      printf("Telefono: %i \n", cliente[arreglo].telefono);
      printf("Desea eliminar la informacion ? \n");
      printf("[1] SI, [2] NO \n");
      scanf("%i", & opc);
      if (opc == 1) {
		
        printf("Eliminando cliente");
        cargando();
        while(i<auxCl){
        	cliente[i]=cliente[i+1];
        	i++;
		}
		auxCl-=1;
      }
    }
  }
  if (flagCli == 0) {
    printf("--- No se encontro al cliente --- \n");
    getch();
  }
}

void mostrarClientes() {
  if (auxCl > 0) {
    printf("--- Clientes --- \n");
    for (i = 0; i <= auxCl - 1; i++) {
      printf("Numero: %i \n", cliente[i].numeroCliente);
      printf("Nombre: %s \n", cliente[i].nombre);
      printf("Apellidos: %s \n", cliente[i].apellidos);
      printf("Edad: %i \n", cliente[i].edad);
      printf("Telefono: %i \n", cliente[i].telefono);
      printf("---------------------------------- \n");
      
    }
    getch();
  } else {
    printf("Sin clientes capturados \n");
    getch();
  }
}

void menuConsultas() {
  int opc;
  do {
  	system("cls");
    printf("--- Menu Consultas --- \n");
    printf("[1] Registro \n");
    printf("[2] Busqueda \n");
    printf("[3] Eliminacion \n");
    printf("[4] Consulta de informacion \n");
    printf("[5] Volver al menu \n");
    scanf("%i", & opc);
    switch (opc) {
    case 1:
    	system("cls");
      registrarConsulta(consulta, & auxCon);
      break;

    case 2:
    	system("cls");
      buscarConsulta();
      break;

    case 3:
    	system("cls");
      eliminarConsulta();
      break;

    case 4:
    	system("cls");
      mostrarConsulta();
      break;
    }

  } while (opc != 5);
}

void registrarConsulta(consultas consulta[], int * auxCon) {
  if ( * auxCon < 20) {

    printf("Ingrese el numero de consulta: \n");
    scanf("%i", & consulta[ * auxCon].numeroConsulta);

    printf("Ingrese el nombre del paciente: \n");
    fflush(stdin);
    gets(consulta[ * auxCon].nombre);

    printf("Ingrese el apellido del paciente: \n");
    fflush(stdin);
    gets(consulta[ * auxCon].apellidos);

    printf("Ingrese la fecha de la consulta: \n");
    fflush(stdin);
    gets(consulta[ * auxCon].fecha);

    printf("Ingrese la hora de la consulta: \n");
    fflush(stdin);
    gets(consulta[ * auxCon].hora);

    * auxCon = * auxCon + 1;

  } else {
    printf("Ya no se pueden agregar más consultas \n");
    getch();
  }
}

void buscarConsulta() {
  int numero, subopc;
  flagCon = 0;

  printf("Ingrese el numero de la consulta: \n");
  scanf("%i", & numero);
  for (i = 0; i <= auxCon - 1; i++) {
    if (numero == consulta[i].numeroConsulta) {
      arreglo = i;
      flagCon = 1;
      do {
        printf("--- Submenu Consultas cambios --- \n");
        printf("[1] Nombre \n");
        printf("[2] Apellidos \n");
        printf("[3] Fecha \n");
        printf("[4] Hora \n");
        printf("[5] Regresar al menu de Consultas \n");
        scanf("%i", & subopc);
        switch (subopc) {
        case 1:
          printf("Anterior nombre: %s \n", consulta[arreglo].nombre);
          printf("Nuevo nombre: \n");
          fflush(stdin);
          gets(consulta[arreglo].nombre);
          break;
        case 2:
          printf("Anteriores apellidos: %s \n", consulta[arreglo].apellidos);
          printf("Nuevos apellidos: \n");
          fflush(stdin);
          gets(consulta[arreglo].apellidos);
          break;
        case 3:
          printf("Anterior fecha: %s \n", consulta[arreglo].fecha);
          printf("Nueva fecha: \n");
          fflush(stdin);
          gets(consulta[arreglo].fecha);
          break;
        case 4:
          printf("Anterior hora: %s \n", consulta[arreglo].hora);
          printf("Nueva hora: \n");
          fflush(stdin);
          gets(consulta[arreglo].hora);
          break;
        }
      } while (subopc != 5);
    }
  }
  if (flagCon == 0) {
    printf("--- No se encontro la consulta --- \n");
    getch();
  }
}

void eliminarConsulta() {
  int numero, opc;
  flagCon = 0;

  printf("Ingrese el numero de la consulta: \n");
  scanf("%d", & numero);
  
  for (i = 0; i <= auxCon - 1; i++) {
    if (numero == consulta[i].numeroConsulta) {
      arreglo = i;
      flagCon = 1;
      printf("Numero: %i \n", consulta[arreglo].numeroConsulta);
      printf("Nombre: %s \n", consulta[arreglo].nombre);
      printf("Apellidos: %s \n", consulta[arreglo].apellidos);
      printf("Fecha: %s \n", consulta[arreglo].fecha);
      printf("Hora: %s \n", consulta[arreglo].hora);
      printf("Desea eliminar la informacion ? \n");
      printf("[1] SI, [2] NO \n");
      scanf("%i", & opc);
      if (opc == 1) {

        printf("Eliminando consulta");
        cargando();
        while(i<auxCon){
        	consulta[i]=consulta[i+1];
        	i++;
		}
		auxCon-=1;
      }
    }
  }
  if (flagCon == 0) {
    printf("--- No se encontro la consulta --- \n");
    getch();
  }
}

void mostrarConsulta() {
  if (auxCon > 0) {
    printf("--- Consultas --- \n");
    for (i = 0; i <= auxCon - 1; i++) {
      printf("Numero: %i \n", consulta[i].numeroConsulta);
      printf("Nombre: %s \n", consulta[i].nombre);
      printf("Apellidos: %s \n", consulta[i].apellidos);
      printf("Fecha: %s \n", consulta[i].fecha);
      printf("Hora: %s \n", consulta[i].hora);
      printf("---------------------------------- \n");
   
    }
       getch();
  } else {
    printf("Sin consultas capturadas \n");
  	getch();
  }
}

void cargando(){
	int x=0;
	while(x<5){
		printf(".");
		Sleep(400);
		x++;
	}
}

void pantallaCarga(){
	int segundos=5;
	int i;
    for(i=0; i<=21; i++)
        printf("\n");
    printf ("\t\t\t\t   CARGANDO...\n");
   
    for(i=0; i<=79; i++)
    {
        printf("%c",219);
        Sleep(segundos*1000/80);
    }
    printf("\nCompletado!");
}
