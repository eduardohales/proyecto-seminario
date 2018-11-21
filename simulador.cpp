#include "simulador.h"

Simulador::Simulador(){
	this->blocked = 0;
	this->llegadasExe = 0;
	this->llegadasTot = 0;
    this->MU=0;
    this->LAMBDA=0;
    this->LAMBDAPRIMA=0;
    this->ton=0;
    this->toff = 0;
    this->cargaTrafico = 0;
    this->cnxBlocked = NULL;
    this->cnxLlegadas = NULL;
    this->cnxEject = NULL;
    this->canalesLibres = 0;
    this->probBloq = 0;
    this->probUser = NULL;
    //this->grafo = NULL;
}
Simulador::~Simulador(){

}
//metodos
double Simulador::getMU(){
	return this->MU;
}
double Simulador::getLAMBDA(){
	return this->LAMBDA;
}
double Simulador::getLAMBDAPRIMA(){
	return this->LAMBDAPRIMA;
}
double Simulador::getton(){
	return this->ton;
}
double Simulador::gettoff(){
	return this->toff;
}
double Simulador::getcargaTrafico(){
	return this->cargaTrafico;
}
int Simulador::getblocked(){
	return this->blocked;
}
int Simulador::getllegadasExe(){
	return this->llegadasExe;
}
int Simulador::getllegadasTot(){
	return this->llegadasTot;
}
float Simulador::getProbBloq(){
	return this->probBloq;
}
float * Simulador::getProbUser(){
	return this->probUser;
}


void Simulador::setllegadasTot(int llegadasTot){
	this->llegadasTot = llegadasTot;
}
void Simulador::setMU(double MU){
	this->MU = MU;
}
void Simulador::setLAMBDA(double LAMBDA){
	this->LAMBDA = LAMBDA;
}
void Simulador::setTON(double ton){
	this->ton = ton;
}
void Simulador::setTOFF(double toff){
	this->toff = toff;
}
void Simulador::setcargaTrafico(double cargaTrafico){
	this->cargaTrafico = cargaTrafico;

}






