#include "VideoStreamingApp.hpp"
#include "consola.hpp"
#include "NoContentAvailable.hpp"
#include "IncorrectRating.hpp"
#include "NoStructureCorrect.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>

VideoStreamingApp::VideoStreamingApp():videos(){}

void VideoStreamingApp::start(){

    int op;

    while (true){
        std::cout << graphInterface();
        std::cin >> op;
        switch (op) {
            case 1 : {
                std::string file;
                std::cout << "Ingrese el nombre del archivo: ";
                std::cin >> file;
                fileUpload(file);
                pausa();
                break;
            }
            case 2 : {
                std::string result = genreOrRating();
                for (const auto& video : videos) {
                    try{
                        if (video->getGenre() == result || video->getAverageRating() == std::stoi(result)){
                            std::cout << video->show() << std::endl;
                        }
                    } catch (std::invalid_argument& e){
                        continue;
                    }
                }
                pausa();
                break;
            }
            case 3 : {
                std::string result = genreOrRating();
                for (const auto& video : videos) {
                    try{
                        if (auto series = dynamic_cast<Series*>(video) && (video->getGenre() == result || video->getAverageRating() == std::stoi(result))) {
                            std::cout << video->show() << std::endl;
                        }
                    } catch (std::invalid_argument& e){
                        continue;
                    }
                }
                pausa();
                break;
            }
            case 4 : {
                std::string result = genreOrRating();
                for (const auto& video : videos) {
                    try{
                        if (auto movie = dynamic_cast<Movie*>(video) && (video->getGenre() == result || video->getAverageRating() == std::stoi(result))) {
                            std::cout << video->show() << std::endl;
                        }
                    } catch (std::invalid_argument& e){
                        continue;
                    }
                }
                pausa();
                break;
            }
            case 5 : {
                try{
                    std::string name; int rating;
                    std::cout << "Ingrese el nombre del contenido: ";
                    std::getline (std::cin >> std::ws, name);
                    std::cout << "Ingrese el rating: ";
                    std::cin >> rating;
                    if(rating < 1 || rating > 5){throw IncorrectRating();} 
                    searchVideoToRate(name, rating);
                }
                catch (IncorrectRating& e){
                    std::cout << e.what() << std::endl;
                }
                pausa();
                break;
            }
            case 6 : {
                int debugnum; int index;
                std::cout << "Herramienta de Debug para Desarrolladores - Aumentar promedio de calificación " << std::endl;
                std::cout << "Ingrese el numero deseado: ";
                std::cin >> debugnum;
                std::cout << "Ingrese el index del contenido deseado: ";
                std::cin >> index;
                videos[index] + debugnum;
                pausa();
                break;
            }
            case 0 : {

                for (const auto& video : videos) {
                    delete video;
                }

                return;
            }
            default : {
                std::cout << "Opción inválida\n";
                pausa();
                break;
            }
        }
        cls();
    }
}

void VideoStreamingApp::fileUpload(std::string file){
    std::ifstream f(file);
    nlohmann::json data = nlohmann::json::parse(f);
    
    try {
        if (!data.contains("movies") || !data.contains("series")){
            throw NoStructureCorrect();
        }
    }
    catch (NoStructureCorrect& e){
        std::cout << e.what() << std::endl;
        pausa();
        return;
    }

    // Parse Movies
    for (const auto& movieData : data["movies"]){
        int id = movieData["id"];
        std::string name = movieData["name"];
        int duration = movieData["duration"];
        std::string genre = movieData["genre"];
        videos.push_back(new Movie(id, name, duration, genre));
    }

    // Parse Series
    for (const auto& seriesData : data["series"]){
        int id = seriesData["id"];
        std::string name = seriesData["name"];
        int duration = seriesData["duration"];
        std::string genre = seriesData["genre"];
        Series* series = new Series(id, name, duration, genre);

        // Parse Episodes
        for (const auto& episodeData : seriesData["episodes"]) {
            std::string episodeName = episodeData["name"];
            int season = episodeData["season"];
            series->addEpisode(Episode(episodeName, season));
        }

        videos.push_back(series);
    }
}

void VideoStreamingApp::searchVideoToRate(std::string name, int rating){
    try{
        for (const auto& video : videos) {
            if (video->getName() == name) {
                video->rate(rating);
                video->updateAverageRating();
                return;
            }
        } throw NoContentAvailable();
        
    } 
    catch (NoContentAvailable& e){
        std::cout << e.what() << std::endl;
        pausa();
        return;
    }
}

std::string VideoStreamingApp::graphInterface(){
    std::string result = "";
    result += "***************************************************************************************************\n";
    result += "                                           MENU PRINCIPAL                                           \n";
    result += "***************************************************************************************************\n";
    result += "1. Cargar archivo de datos\n";
    result += "2. Mostrar los videos en general con una cierta calificación o de un cierto género\n";
    result += "3. Mostrar los episodios de una determinada serie con una cierta calificación o de un cierto género\n";
    result += "4. Mostrar las películas con una cierta calificación o de un cierto género\n";
    result += "5. Calificar un video\n";
    result += "0. Salir\n";
    result += "***************************************************************************************************\n";
    result += ">> ";
    return result;
}

std::string VideoStreamingApp::genreOrRating() {
    int showOp; std::string userInput;

    std::cout << "1. Mostrar por rating\n";
    std::cout << "2. Mostrar por género\n";
    std::cout << ">> ";
    std::cin >> showOp;

    switch (showOp) {
        case 1: {
            std::cout << "Ingrese el rating: ";
            std::cin >> userInput;
            break;
        }
        case 2: {
            std::cout << "Ingrese el género: ";
            std::cin >> userInput;
            break;
        }
        default:
            std::cout << "Opción inválida\n";
            pausa();
            break;
    }

    return userInput;
}