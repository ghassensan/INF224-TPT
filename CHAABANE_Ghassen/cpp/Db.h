#ifndef DB_H
#define DB_H

#include <map>
#include <memory>
#include <sstream>
#include <ostream>
#include "Multimedia.h"
#include "Group.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include"tcpserver.h"

/**
 * @brief The Db class
 */
class Db
{
private:
    // variable d'instance
    std::map<std::string, std::shared_ptr<Multimedia>> mediaTable;
    std::map<std::string, std::shared_ptr<Group>> groupTable;

public:
    // Constructeur
    /**
     * @brief Db
     */
    Db();

    // New
    /**
     * @brief newPhoto
     * @param _name
     * @param _path
     * @param _latitude
     * @param _longitude
     * @return
     */
    std::shared_ptr<Photo> newPhoto(std::string _name="", std::string _path="", float _latitude = 0.0f, float _longitude = 0.0f);
    /**
     * @brief newVideo
     * @param _name
     * @param _path
     * @param _duration
     * @return
     */
    std::shared_ptr<Video> newVideo(std::string _name="", std::string _path="", unsigned long long int _duration = 0ll);
    /**
     * @brief newFilm
     * @param _name
     * @param _path
     * @param _duration
     * @param _chap
     * @param _nbrChap
     * @return
     */
    std::shared_ptr<Film> newFilm(std::string _name="", std::string _path="", unsigned long long int _duration = 0ll,
                                  int * _chap = nullptr, unsigned int _nbrChap = 0);
    /**
     * @brief newGroup
     * @param _name
     * @return
     */
    std::shared_ptr<Group> newGroup(std::string _name="");

    // Find
    /**
     * @brief findMedia
     * @param _name
     * @return
     */
    std::shared_ptr<Multimedia> findMedia(std::string _name);
    /**
     * @brief findGroup
     * @param _name
     * @return
     */
    std::shared_ptr<Group> findGroup(std::string _name);

    // Print & Play
    /**
     * @brief printMedia
     * @param _name
     * @param out
     */
    void printMedia(std::string _name, std::ostream& out = std::cout);
    /**
     * @brief printGroup
     * @param _name
     * @param out
     */
    void printGroup(std::string _name, std::ostream& out = std::cout);
    /**
     * @brief play
     * @param _name
     */
    void play(std::string _name);
    /**
     * @brief listAllMedias
     * @return
     */
    std::string listAllMedias();
    /**
     * @brief listAllGroups
     * @return
     */
    std::string listAllGroups();

    /**
     * @brief processRequest
     * @param cnx
     * @param request
     * @param response
     * @return
     */
    bool processRequest(cppu::TCPConnection& cnx, const std::string& request, std::string& response);

};

#endif // DB_H
