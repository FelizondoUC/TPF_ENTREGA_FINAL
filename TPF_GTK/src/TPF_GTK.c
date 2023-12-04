/*
 ============================================================================
 Name        : TPF_GTK.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in GTK+
 ============================================================================
 */

#include <gtk/gtk.h>
#include <stdlib.h>
#include "variables.h"
#include "TPF_4.0.h"
#include "humano.h"

GtkWidget *Ventana_Principal;
GtkWidget *ventanaReglas1;
GtkWidget *Ventana_Reglas2;
GtkWidget *Ventana_Creditos;
GtkWidget *Ventana_Jugar;
GtkWidget *Ventana_Jugar2;
GtkWidget *Ventana_Empezar_Partida;
GtkWidget *Ventana_Rendirse;

GObject *Boton_Reglas_Menu;
GObject *Volver_A_Menu_Reglas1;
GObject *Boton_Siguiente_Reglas;
GObject *Boton_PaganteReglas1_Reglas2;
GObject *Volver_A_Menu_Reglas2;
GObject *Boton_Creditos;
GObject *Volver_A_Menu_Creditos;
GObject *Boton_Jugar;
GObject *Volver_al_Menu_Jugar;
GtkToggleButton *Humano_VS_PC;
GtkToggleButton *PC_vs_Humano;
GtkToggleButton *Al_Azar;
GtkToggleButton *PC_vs_PC;
GtkToggleButton *Seleccionar_Red;
GtkToggleButton *Seleccionar_Green;
GObject *Siguiente_Jugar;
GObject *Volver_al_Menu_Jugar2;
GtkToggleButton *IA_Aleatoria;
GtkToggleButton *IA_Inteligente;
GtkBuilder *builder;
GtkEntry *Nombre_Jugador1;
GtkEntry *Nombre_Jugador2;
GObject *Siguiente_Jugar2;
GObject *Boton_Ayuda_Juego;
GObject *Boton_Acerca_de_Juego;
GObject *Boton_Rendirse_Juego;
GObject *Boton_continuar_ventRendirse;
GObject *Rendirse_Ventana_Rendirse;

GObject *Botones[25];
GtkWidget *Dados[25];

int opcion;
int IA;
int player;
int board_gtk[TAM_MAX][TAM_MAX];

void funcOcultar(GObject *widet, gpointer data)
{
	gtk_widget_hide(data);
}

void funcLlamar(GObject *cosito, gpointer data)
{
	gtk_widget_show_all (data);
}

void funcMostrarOcultar1 (GObject *boton, gpointer data)
{
	gtk_widget_hide(ventanaReglas1);
	gtk_widget_show_all (Ventana_Reglas2);
}

void funcMostrarOcultar2 (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Reglas2);
	gtk_widget_show_all (ventanaReglas1);
}

void funcMostrarOcultar3 (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Principal);
	gtk_widget_show_all (Ventana_Jugar);
}

void funcMostrarOcultar4 (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Jugar);
	gtk_widget_show_all (Ventana_Principal);
}

void funcMostrarOcultar5 (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Jugar);
	gtk_widget_show_all (Ventana_Jugar2);
}

void funcMostrarOcultar6 (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Jugar2);
	gtk_widget_show_all (Ventana_Jugar);
}

void funcMostrarOcultar7 (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Empezar_Partida);
	gtk_widget_hide(Ventana_Rendirse);
	gtk_widget_show_all (Ventana_Principal);
}

void funcBotonesModoJuego1(GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PC_vs_Humano), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Al_Azar), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PC_vs_PC), FALSE);
		opcion = 1;
		player = PLAYER1;

	}
}

void funcBotonesModoJuego2(GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Humano_VS_PC), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Al_Azar), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PC_vs_PC), FALSE);
		opcion = 2;
		player = PLAYER2;
	}
}

void funcBotonesModoJuego3(GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PC_vs_Humano), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Humano_VS_PC), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PC_vs_PC), FALSE);
		opcion = 4;
	}
}

void funcBotonesModoJuego4(GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PC_vs_Humano), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Al_Azar), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Humano_VS_PC), FALSE);
		opcion = 3;
	}
}
	void funcColorRed(GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Seleccionar_Green), FALSE);
		colorP1 = 1;
		colorP2 = 2;
		//Asigna dados del 1 al 6 (dados rojos)

	}
}

void funcColorGreen(GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Seleccionar_Red), FALSE);
		colorP1 = 2;
		colorP2 = 1;
	}
}

void funcBotonesIA1 (GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
		{
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(IA_Inteligente), FALSE);
			IA = 1;
		}
}

void funcBotonesIA2 (GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
		{
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(IA_Aleatoria), FALSE);
			IA = 3;
		}
}


void comenzar_juego (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Jugar2);
	gtk_widget_show_all (Ventana_Empezar_Partida);
	main_C (opcion, colorP1, IA);

}

void obtener_tablero (int x, int y, int turno)
{
	if (turno == PLAYER1)
	{
		juegaHumano(x, y, player);
	}

	if (opcion == 1)
	{

		for (int a = 0;a < 5;a++)
		{
			for (int b = 0;b < 5;b++)
			{


			}
		}
	}else if (opcion == 2) {
		juegaPc(player, IA);
		for (int a = 0;a < 5;a++)
		{
			for (int b = 0;b < 5;b++)
			{

			}
		}
	}
}

void actualizar_boton1()
{
	//int x = 0, y = 0;
	obtener_tablero(0, 0, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[0][0];


		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenA5 = GTK_WIDGET(gtk_builder_get_object(builder, "i1"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenA5), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[0][0];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[0][0] = board[0][0];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}


			GtkWidget *botonA5 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenA5 = GTK_WIDGET(gtk_builder_get_object(builder, "i1"));

			 if (estado != 0)
			        	gtk_widget_set_sensitive(botonA5, FALSE);
			        else
			        	gtk_widget_set_sensitive(botonA5, TRUE);

				// Construir la ruta completa del archivo de imagen
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenA5), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton2()
{
	//int x = 0, y = 1;
	obtener_tablero(0, 1, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[0][1];

		//copiamos la matriz usada para las jugadas en la matriz para el GTK
		board_gtk[0][1] = board[0][1];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenB5 = GTK_WIDGET(gtk_builder_get_object(builder, "i2"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenB5), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[0][1];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[0][1] = board[0][1];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenB5 = GTK_WIDGET(gtk_builder_get_object(builder, "i2"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenB5), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j]);
			}
		}
	printf("\n");
}

void actualizar_boton3()
{
	int x = 0, y = 2;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//copiamos la matriz usada para las jugadas en la matriz para el GTK
		board_gtk[x][y] = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenC5 = GTK_WIDGET(gtk_builder_get_object(builder, "i3"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenC5), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenC5 = GTK_WIDGET(gtk_builder_get_object(builder, "i3"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenC5), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");

}

void actualizar_boton4()
{
	int x = 0, y = 3;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//copiamos la matriz usada para las jugadas en la matriz para el GTK
		board_gtk[x][y] = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenD5 = GTK_WIDGET(gtk_builder_get_object(builder, "i4"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenD5), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenD5 = GTK_WIDGET(gtk_builder_get_object(builder, "i4"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenD5), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton5()
{
	int x = 0, y = 4;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//copiamos la matriz usada para las jugadas en la matriz para el GTK
		board_gtk[x][y] = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenE5 = GTK_WIDGET(gtk_builder_get_object(builder, "i5"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenE5), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenE5 = GTK_WIDGET(gtk_builder_get_object(builder, "i5"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenE5), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton6()
{
	int x = 1, y = 0;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//copiamos la matriz usada para las jugadas en la matriz para el GTK
		board_gtk[x][y] = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenA4 = GTK_WIDGET(gtk_builder_get_object(builder, "i6"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenA4), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenA4 = GTK_WIDGET(gtk_builder_get_object(builder, "i6"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenA4), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton7()
{
	int x = 1, y = 1;
	obtener_tablero(x, y, 1);
	GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
	GtkWidget *imagenB4 = GTK_WIDGET(gtk_builder_get_object(builder, "i7"));
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//copiamos la matriz usada para las jugadas en la matriz para el GTK
		board_gtk[x][y] = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen

		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenB4), rutaImagen);

	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenB4 = GTK_WIDGET(gtk_builder_get_object(builder, "i7"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenB4), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton8()
{
	int x = 1, y = 2;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//copiamos la matriz usada para las jugadas en la matriz para el GTK
		board_gtk[x][y] = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenC4 = GTK_WIDGET(gtk_builder_get_object(builder, "i8"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenC4), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenC4 = GTK_WIDGET(gtk_builder_get_object(builder, "i8"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenC4), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton9()
{
	int x = 1, y = 3;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//copiamos la matriz usada para las jugadas en la matriz para el GTK
		board_gtk[x][y] = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenD4 = GTK_WIDGET(gtk_builder_get_object(builder, "i9"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenD4), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenD4 = GTK_WIDGET(gtk_builder_get_object(builder, "i9"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenD4), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton10()
{
	int x = 1, y = 4;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenE4 = GTK_WIDGET(gtk_builder_get_object(builder, "i10"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenE4), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenE4 = GTK_WIDGET(gtk_builder_get_object(builder, "i10"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenE4), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton11()
{
	int x = 2, y = 0;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenA3 = GTK_WIDGET(gtk_builder_get_object(builder, "i11"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenA3), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenA3 = GTK_WIDGET(gtk_builder_get_object(builder, "i11"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenA3), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton12()
{
	int x = 2, y = 1;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenB3 = GTK_WIDGET(gtk_builder_get_object(builder, "i12"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenB3), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenB3 = GTK_WIDGET(gtk_builder_get_object(builder, "i12"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenB3), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton13()
{
	int x = 2, y = 2;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenC3 = GTK_WIDGET(gtk_builder_get_object(builder, "i13"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenC3), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenC3 = GTK_WIDGET(gtk_builder_get_object(builder, "i13"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenC3), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton14()
{
	int x = 2, y = 3;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenD3 = GTK_WIDGET(gtk_builder_get_object(builder, "i14"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenD3), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenD3 = GTK_WIDGET(gtk_builder_get_object(builder, "i14"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenD3), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton15()
{
	int x = 2, y = 4;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenE3 = GTK_WIDGET(gtk_builder_get_object(builder, "i15"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenE3), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenE3 = GTK_WIDGET(gtk_builder_get_object(builder, "i15"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenE3), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton16()
{
	int x = 3, y = 0;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenA2 = GTK_WIDGET(gtk_builder_get_object(builder, "i16"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenA2), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenA2 = GTK_WIDGET(gtk_builder_get_object(builder, "i16"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenA2), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton17()
{
	int x = 3, y = 1;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenB2 = GTK_WIDGET(gtk_builder_get_object(builder, "i17"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenB2), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenB2 = GTK_WIDGET(gtk_builder_get_object(builder, "i17"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenB2), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton18()
{
	int x = 3, y = 2;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenC2 = GTK_WIDGET(gtk_builder_get_object(builder, "i18"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenC2), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenC2 = GTK_WIDGET(gtk_builder_get_object(builder, "i18"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenC2), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton19()
{
	int x = 3, y = 3;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenD2 = GTK_WIDGET(gtk_builder_get_object(builder, "i19"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenD2), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenD2 = GTK_WIDGET(gtk_builder_get_object(builder, "i19"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenD2), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton20()
{
	int x = 3, y = 4;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenE2 = GTK_WIDGET(gtk_builder_get_object(builder, "i20"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenE2), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenE2 = GTK_WIDGET(gtk_builder_get_object(builder, "i20"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenE2), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton21()
{
	int x = 4, y = 0;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenA1 = GTK_WIDGET(gtk_builder_get_object(builder, "i21"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenA1), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenA1 = GTK_WIDGET(gtk_builder_get_object(builder, "i21"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenA1), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton22()
{
	int x = 4, y = 1;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenB1 = GTK_WIDGET(gtk_builder_get_object(builder, "i22"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenB1), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenB1 = GTK_WIDGET(gtk_builder_get_object(builder, "i22"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenB1), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton23()
{
	int x = 1, y = 4;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenC1 = GTK_WIDGET(gtk_builder_get_object(builder, "i23"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenC1), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenC1 = GTK_WIDGET(gtk_builder_get_object(builder, "i23"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenC1), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton24()
{
	int x = 4, y = 3;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenD1 = GTK_WIDGET(gtk_builder_get_object(builder, "i24"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenD1), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenD1 = GTK_WIDGET(gtk_builder_get_object(builder, "i24"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenD1), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizar_boton25()
{
	int x = 4, y = 4;
	obtener_tablero(x, y, 1);
	if (opcion == 1 && colorP1 == 1 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
		int estado = board[x][y];

		//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
		char *nombreImagen = "Nada.jpeg";
		if (estado == 1){
			nombreImagen = "Dado_Rojo1.jpeg";
		}else if (estado == 2){
			nombreImagen = "Dado_Rojo2.jpeg";
		}else if (estado == 3){
			nombreImagen = "Dado_Rojo3.jpeg";
		}else if (estado == 4){
			nombreImagen = "Dado_Rojo4.jpeg";
		}else if (estado == 5){
			nombreImagen = "Dado_Rojo5.jpeg";
		}else if (estado == 6){
			nombreImagen = "Dado_Rojo6.jpeg";
		}else if (estado == 7){
			nombreImagen = "Dado_Verde1.jpeg";
		}else if (estado == 8){
			nombreImagen = "Dado_Verde2.jpeg";
		}else if (estado == 9){
			nombreImagen = "Dado_Verde3.jpeg";
		}else if (estado == 10){
			nombreImagen = "Dado_Verde4.jpeg";
		}else if (estado == 11){
			nombreImagen = "Dado_Verde5.jpeg";
		}else if (estado == 12){
			nombreImagen = "Dado_Verde6.jpeg";
		}

		// Construir la ruta completa del archivo de imagen
		//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
		GtkWidget *imagenE1 = GTK_WIDGET(gtk_builder_get_object(builder, "i25"));
		char rutaImagen[100];
		snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

		// Actualizar la imagen
		gtk_image_set_from_file(GTK_IMAGE(imagenE1), rutaImagen);
	}else if (opcion == 1 && colorP1 == 2 && IA == 1)
	{	//obtenemos el estado de la posicion en la matriz
			int estado = board[x][y];

			//copiamos la matriz usada para las jugadas en la matriz para el GTK
			board_gtk[x][y] = board[x][y];

			//Asignamos a una variable el nombre de la imagen dependiendo del numero de la matriz que tendremos y de la opcion elegida
			char *nombreImagen = "Nada.jpeg";
			if (estado == 1){
				nombreImagen = "Dado_Verde1.jpeg";
			}else if (estado == 2){
				nombreImagen = "Dado_Verde2.jpeg";
			}else if (estado == 3){
				nombreImagen = "Dado_Verde3.jpeg";
			}else if (estado == 4){
				nombreImagen = "Dado_Verde4.jpeg";
			}else if (estado == 5){
				nombreImagen = "Dado_Verde5.jpeg";
			}else if (estado == 6){
				nombreImagen = "Dado_Verde6.jpeg";
			}else if (estado == 7){
				nombreImagen = "Dado_Rojo1.jpeg";
			}else if (estado == 8){
				nombreImagen = "Dado_Rojo2.jpeg";
			}else if (estado == 9){
				nombreImagen = "Dado_Rojo3.jpeg";
			}else if (estado == 10){
				nombreImagen = "Dado_Rojo4.jpeg";
			}else if (estado == 11){
				nombreImagen = "Dado_Rojo5.jpeg";
			}else if (estado == 12){
				nombreImagen = "Dado_Rojo6.jpeg";
			}

			// Construir la ruta completa del archivo de imagen
			//GtkWidget *botonA1 = GTK_WIDGET(gtk_builder_get_object(builder, "1"));
			GtkWidget *imagenE1 = GTK_WIDGET(gtk_builder_get_object(builder, "i25"));
			char rutaImagen[100];
			snprintf(rutaImagen, sizeof(rutaImagen), "/home/lp1-2023/eclipse-workspace/TPF_GTK/%s", nombreImagen);

			// Actualizar la imagen
			gtk_image_set_from_file(GTK_IMAGE(imagenE1), rutaImagen);
		}
	for (int i = 0; i < TAM_MAX; i++) {
			printf("\n");
			for (int j = 0; j < TAM_MAX; j++) {
				if ( board_gtk[i][j] >= 0 &&  board_gtk[i][j] <= 6)
					printf("  %d ",  board_gtk[i][j]);
				else
					printf(" *%d ", board_gtk[i][j] - 6);
			}
		}
	printf("\n");
}

void actualizarTablero (GtkWidget *widget, gpointer data)
{
	actualizar_boton1();
	actualizar_boton2();
	actualizar_boton3();
	actualizar_boton4();
	actualizar_boton5();
	actualizar_boton6();
	actualizar_boton7();
	actualizar_boton8();
	actualizar_boton9();
	actualizar_boton10();
	actualizar_boton11();
	actualizar_boton12();
	actualizar_boton13();
	actualizar_boton14();
	actualizar_boton15();
	actualizar_boton16();
	actualizar_boton17();
	actualizar_boton18();
	actualizar_boton19();
	actualizar_boton20();
	actualizar_boton21();
	actualizar_boton22();
	actualizar_boton23();
	actualizar_boton24();
	actualizar_boton25();


}

 int main (int argc, char *argv[])
 {
	 //Punteros a elementos del Glade
    gtk_init (&argc, &argv);

    builder = gtk_builder_new_from_file("TPFgtk.V1");
    Ventana_Principal = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana_Principal"));
    Ventana_Creditos = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana_Creditos"));
    ventanaReglas1 = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana_Reglas1"));
    Ventana_Reglas2 = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana_Reglas2"));
    Ventana_Jugar = GTK_WIDGET(gtk_builder_get_object(builder, "Ventana_Jugar"));
    Ventana_Jugar2 = GTK_WIDGET(gtk_builder_get_object(builder, "Ventana_Jugar2"));
    Ventana_Empezar_Partida = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana_Empezar_Partida"));
    Ventana_Rendirse = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana_Rendirse"));

    //Asiganción de los botones de las distintas ventanas
    Boton_Reglas_Menu = gtk_builder_get_object(builder,"Boton_Reglas_Menu");
    Volver_A_Menu_Reglas1 = gtk_builder_get_object(builder, "Volver_A_Menu_Reglas1");
    Boton_Siguiente_Reglas = gtk_builder_get_object(builder,"Boton_Siguiente_Reglas");
    Boton_PaganteReglas1_Reglas2 = gtk_builder_get_object(builder, "Boton_PaganteReglas1_Reglas2");
    Volver_A_Menu_Reglas2 = gtk_builder_get_object(builder, "Volver_A_Menu_Reglas2");
    Boton_Creditos = gtk_builder_get_object(builder, "Boton_Creditos");
    Volver_A_Menu_Creditos = gtk_builder_get_object(builder, "Volver_A_Menu_Creditos");
    Boton_Jugar = gtk_builder_get_object(builder,"Boton_Jugar");
    Volver_al_Menu_Jugar = gtk_builder_get_object(builder,"Volver_al_Menu_Jugar");
    Humano_VS_PC = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"Humano_VS_PC"));
    PC_vs_Humano = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"PC_vs_Humano"));
    Al_Azar = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"Al_Azar"));
    PC_vs_PC = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"PC_vs_PC"));
    Seleccionar_Red = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"Seleccionar_Red"));
    Seleccionar_Green = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"Seleccionar_Green"));
    Siguiente_Jugar = gtk_builder_get_object(builder,"Siguiente_Jugar");
    Volver_al_Menu_Jugar2 = gtk_builder_get_object(builder, "Volver_al_Menu_Jugar2");
    IA_Aleatoria = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"IA_Aleatoria"));
    IA_Inteligente = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"IA_Inteligente"));
    Nombre_Jugador1 = GTK_ENTRY(gtk_builder_get_object(builder,"Nombre_Jugador1"));
    Nombre_Jugador2 = GTK_ENTRY(gtk_builder_get_object(builder,"Nombre_Jugador2"));
    Siguiente_Jugar2 = gtk_builder_get_object(builder,"Siguiente_Jugar2");
    Boton_Ayuda_Juego = gtk_builder_get_object (builder,"Boton_Ayuda_Juego");
    Boton_Acerca_de_Juego = gtk_builder_get_object (builder,"Boton_Acerca_de_Juego");
    Boton_Rendirse_Juego = gtk_builder_get_object (builder,"Boton_Rendirse_Juego");
    Boton_continuar_ventRendirse = gtk_builder_get_object (builder,"Boton_continuar_ventRendirse");
    Rendirse_Ventana_Rendirse = gtk_builder_get_object (builder,"Rendirse_Ventana_Rendirse");



    //Asignacion de los punteros de los botones del tablero
    for (int i = 1; i < 26; i++)
    {
    	char num_boton[3];
    	if (i < 10)
    	{
    		num_boton[0] = '0' + i;
    		num_boton[1] = '\0';
    	}else {
    		num_boton[0] = '0' + (i/10);
    		num_boton[1] = '0' + (i%10);
    		num_boton[2] = '\0';
    	}

    	Botones[i]  = gtk_builder_get_object(builder, num_boton);
    }

    //Asignación de las imágenes de los botones del tablero

    for (int k = 1; k < 26; k++)
        {
        	char num_img[4];
        	num_img[0] = 'i';
        	if (k < 10){
        		num_img[1] = '0' + k;
        		num_img[2] = '\0';
        	}else{
        		num_img[1] = '0' + (k/10);
           		num_img[2] = '0' + (k%10);
        		num_img[3] = '\0';
        	}
        	Dados[k] =GTK_WIDGET(gtk_builder_get_object(builder, num_img));
        }

    //Callbacks que terminan el codigo
    g_signal_connect (Ventana_Principal, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect (Ventana_Jugar, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect (Ventana_Jugar2, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect (Ventana_Empezar_Partida, "destroy", G_CALLBACK (gtk_main_quit), NULL);


    g_signal_connect (Boton_Reglas_Menu, "clicked", G_CALLBACK (funcLlamar), ventanaReglas1);
    g_signal_connect (Volver_A_Menu_Reglas1, "clicked", G_CALLBACK (funcOcultar), ventanaReglas1);
    g_signal_connect (Boton_Siguiente_Reglas, "clicked", G_CALLBACK(funcMostrarOcultar1), NULL);
    g_signal_connect (Boton_PaganteReglas1_Reglas2, "clicked", G_CALLBACK(funcMostrarOcultar2), NULL);
    g_signal_connect (Volver_A_Menu_Reglas2, "clicked", G_CALLBACK (funcOcultar), Ventana_Reglas2);
    g_signal_connect (Boton_Creditos, "clicked", G_CALLBACK (funcLlamar), Ventana_Creditos);
    g_signal_connect (Volver_A_Menu_Creditos, "clicked", G_CALLBACK (funcOcultar), Ventana_Creditos);
    g_signal_connect (Boton_Jugar, "clicked", G_CALLBACK (funcMostrarOcultar3), Ventana_Jugar);
    g_signal_connect (Volver_al_Menu_Jugar, "clicked", G_CALLBACK (funcMostrarOcultar4),NULL);
    g_signal_connect (Siguiente_Jugar, "clicked", G_CALLBACK (funcMostrarOcultar5), NULL);
    g_signal_connect (Volver_al_Menu_Jugar2, "clicked", G_CALLBACK (funcMostrarOcultar6), NULL);
    g_signal_connect (Humano_VS_PC, "toggled", G_CALLBACK (funcBotonesModoJuego1), Ventana_Jugar);
    g_signal_connect (PC_vs_Humano, "toggled", G_CALLBACK (funcBotonesModoJuego2), Ventana_Jugar);
    g_signal_connect (Al_Azar, "toggled", G_CALLBACK (funcBotonesModoJuego3), Ventana_Jugar);
    g_signal_connect (PC_vs_PC, "toggled", G_CALLBACK (funcBotonesModoJuego4), Ventana_Jugar);
    g_signal_connect (Seleccionar_Red, "toggled", G_CALLBACK (funcColorRed), Ventana_Jugar);
    g_signal_connect (Seleccionar_Green, "toggled", G_CALLBACK (funcColorGreen), Ventana_Jugar);
    g_signal_connect (IA_Aleatoria, "toggled", G_CALLBACK (funcBotonesIA1), NULL);
    g_signal_connect (IA_Inteligente, "toggled", G_CALLBACK (funcBotonesIA2), NULL);
    g_signal_connect (Siguiente_Jugar2, "clicked", G_CALLBACK(comenzar_juego), NULL);
    g_signal_connect (Boton_Ayuda_Juego, "clicked", G_CALLBACK(funcLlamar), ventanaReglas1);
    g_signal_connect (Boton_Acerca_de_Juego, "clicked", G_CALLBACK(funcLlamar),Ventana_Creditos);
    g_signal_connect (Boton_Rendirse_Juego, "clicked",G_CALLBACK(funcLlamar), Ventana_Rendirse);
    g_signal_connect (Boton_continuar_ventRendirse, "clicked", G_CALLBACK(funcOcultar), Ventana_Rendirse);
    g_signal_connect (Rendirse_Ventana_Rendirse, "clicked", G_CALLBACK(gtk_main_quit),NULL);


    g_signal_connect (Botones[1], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[2], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[3], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[4], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[5], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[6], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[7], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[8], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[9], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[10], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[11], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[12], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[13], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[14], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[15], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[16], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[17], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[18], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[19], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[20], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[21], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[22], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[23], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[24], "clicked", G_CALLBACK(actualizarTablero),NULL);
    g_signal_connect (Botones[25], "clicked", G_CALLBACK(actualizarTablero),NULL);


    gtk_widget_show_all (Ventana_Principal);

    gtk_main ();

    return 0;
 }
