#include "Multimedia.h"
#include<string>
#include<iostream>

using namespace std;

Multimedia::Multimedia(string _name, string _path)
{
    name = _name;
    path = _path;
}

void Multimedia::setName(string _name) {name = _name;}

void Multimedia::setPath(string _path) {path = _path;}

string Multimedia::getName() const {return name;}

string Multimedia::getPath() const {return path;}

Multimedia::~Multimedia(){}

void Multimedia::print(ostream & out) const
{
    out << "=========================================================="<< ";"
        << "Multimedia name is :  " << name << ";"
        << "Multimedia path is :  " << path << ";";
}
