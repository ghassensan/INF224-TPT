#include"Multimedia.h"
#include"Photo.h"
#include"Video.h"
#include"Film.h"
#include"Group.h"
#include"Db.h"
#include "tcpserver.h"

#include <iostream>
#include<memory>

using namespace std;
using namespace cppu;

//#define FIRST_VERSION

const int PORT = 3331;
/**
 * @brief main
 * @return
 */
int main()
{
    // crée le TCPServer
    shared_ptr<TCPServer> server(new TCPServer());

    // crée l'objet qui gère les données
    shared_ptr<Db> MyBase(new Db());
    shared_ptr<Video>video = MyBase->newVideo("video.ogv", "../media/", 200);
    shared_ptr<Photo>photo = MyBase->newPhoto("photo.jpg", "../media/", 100, 100);
    shared_ptr<Group>group = MyBase->newGroup("Groupe");
    group ->push_back(video);
    group ->push_back(photo);

    server->setCallback(*MyBase, &Db::processRequest);

    cout << "Starting Server on port " << PORT << endl;
    int status = server->run(PORT);

    if (status < 0) {
        cerr << "Could not start Server on port " << PORT << endl;
        return 1;
    }

#ifdef FIRST_VERSION

    cout << "\n \n \n \n \n Hello!! CHAABANE Ghassen" << endl;

    //    Photo * photo = new Photo("PhotoName1","PhotoPath1",1.1f,1.1f);
    //    photo->print(cout);
    //    cout << "   First Print done with success !!" << endl;
    //    photo->setName("image.jpg");
    //    photo->setPath("/home/chaabane/Downloads/");
    //    photo->setLatitude(1.2f);
    //    photo->setLongitude(1.2f);
    //    photo->print(cout);
    //    cout << "   Second Print done with success !!" << endl;

    //    photo->play();
    //    delete photo;
    //    photo = nullptr;


    //    Video * video = new Video("VideoName1","VideoPath1",1ll);
    //    video->print(cout);
    //    cout << "   First Print done with success !!" << endl;
    //    video->setName("video.ogv");
    //    video->setPath("/home/chaabane/Downloads/");
    //    video->setDuration(2ll);
    //    video->print(cout);
    //    cout << "   Second Print done with success !!" << endl;
    //    video->play();
    //    delete video;
    //    video = nullptr;

    //    cout << "\n \n \n \n \n I hope u enjoyed it !! CHAABANE Ghassen \n \n" << endl;

    //    Multimedia ** media = new Multimedia * [1];
    //    unsigned int count = 0;
    //    media[count++] = new Photo("image.jpg","/home/chaabane/Downloads/");
    //    media[count++] = new Video("video.ogv","/home/chaabane/Downloads/");

    //    for (unsigned int k = 0; k < count; k++)
    //    {
    //        media[k]->play();
    //    }

    //    delete [] media;
    //    media =nullptr;

    //    Film * film = new Film();
    //    film->getChap();
    //    film->print();

    //    shared_ptr<Video> video(new Video("video", "media/video.mp4", 100));
    //    shared_ptr<Photo> photo(new Photo("tpt", "media/tpt.jpg", 213, 100));
    //    Group* group(new Group(string("Vacances")));

    //    cout << group->getName() << endl;
    //    group->push_back(video);
    //    group->push_back(photo);
    //    group->print();
    //    delete group;
    //    photo->print(cout);
#endif
    return 0;
}
