#include "Db.h"

using namespace std;
using namespace cppu;

// Constructeur
Db::Db(){}

// New
shared_ptr<Photo> Db::newPhoto(string _name, string _path, float _latitude, float _longitude)
{
    shared_ptr<Photo> photo (new Photo(_name, _path, _latitude, _longitude));
    mediaTable[_name] = photo;
    return photo;
}

shared_ptr<Video> Db::newVideo(string _name, string _path, unsigned long long int _duration)
{
    shared_ptr<Video> video (new Video(_name, _path, _duration));
    mediaTable[_name] = video;
    return video;
}

shared_ptr<Film> Db::newFilm(string _name, string _path, unsigned long long int _duration,
                             int * _chap, unsigned int _nbrChap)
{
    shared_ptr<Film> film(new Film(_name, _path, _duration, _chap, _nbrChap));
    mediaTable[_name] = film;
    return film;
}

shared_ptr<Group> Db::newGroup(string _name)
{
    shared_ptr<Group> group(new Group(_name));
    groupTable[_name] = group;
    return group;
}

// Find
shared_ptr<Multimedia> Db::findMedia(string _name)
{
    auto it = mediaTable.find(_name);
    if(it != mediaTable.end())
        return it->second;
    else
        return nullptr;
}

shared_ptr<Group> Db::findGroup(string _name)
{
    auto it = groupTable.find(_name);
    if(it != groupTable.end())
        return it->second;
    else
        return nullptr;
}

// Print & Play
void Db::printMedia(string _name, ostream& out)
{
    auto media = findMedia(_name);
    if(media != nullptr)
    {
        media->print(out);
        return;
    }
    cerr << _name  << " is not in mediaTable" << endl;
}

void Db::printGroup(string _name, ostream& out)
{
    auto group = findGroup(_name);
    if(group != nullptr)
    {
        group->print(out);
        return;
    }
    cerr << _name  << " is not in groupTable" << endl;
}

void Db::play(string _name)
{
    auto media = findMedia(_name);
    if(media != nullptr)
    {
        media->play();
        return;
    }
    cerr << _name  << " is not in mediaTable" << endl;
}

string Db::listAllMedias()
{
    string result = "";
    for(auto & it : mediaTable)
    {
        result += "=====================================;";
        result += "Name : " + it.first+";";
    }
    result += "=====================================;";
    return result;
}

string Db::listAllGroups()
{
    string result = "";
    for(auto & it : groupTable)
    {
        result += "=====================================;";
        result += "Name : " + it.first+";";
    }
    result += "=====================================;";
    return result;
}

bool Db::processRequest(TCPConnection& cnx, const string& request, string& response)
{
    cerr << "\nRequest: '" << request << "'" << endl;

    stringstream req_stream, res_stream;
    req_stream << request;

    string task, name;
    req_stream >> task >> name;

    // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
    // - sinon juste: TCPLock lock(cnx);
    TCPLock lock(cnx);

    if(task == "FINDMEDIA") {
        shared_ptr<Multimedia> result = findMedia(name);
        if(result == nullptr) {
            response = name + " is not found !!;";
        }
        else {
            result->print(res_stream);
            response = res_stream.str();
        }
    }
    else if(task == "FINDGROUP") {
        shared_ptr<Group> result = findGroup(name);
        if(result == nullptr) {
            response =name + " is not found !!;";
        }
        else {
            result->print(res_stream);
            response = res_stream.str();
        }
    }
    else if(task == "LISTMEDIAS") {
        response = listAllMedias();
    }
    else if(task == "LISTGROUPS") {
        response = listAllGroups();
    }
    else if(task == "PLAY") {
        shared_ptr<Multimedia> result = findMedia(name);
        if(result == nullptr) {
            response = name + " is not found !!;";
        }
        else {
            result->play();
            response = name + " is running on the server !!;";
        }
    }
    else if(task == "EXIT") {
        response = "Good Job !!;";
        return false;
    }
    else {
        response = "Please choose one Button! ;";
    }
    cerr << "response: " << response << endl;

    // renvoyer false si on veut clore la connexion avec le client
    return true;
}
