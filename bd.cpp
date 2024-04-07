#include "bd.h"
#include "BatallaNaval.h"
#include "Ahorcado.h"

BD::BD(){

    this->usuarios = {};
    BatallaNaval *batallaNaval = new BatallaNaval("Batalla Naval","1998",1,"Nintendo","Nintendo Switch");
    Ahorcado *ahorcado = new Ahorcado("Ahorcado","1745",1,"Piccaso","Windows");
    this->videoJuegos = {batallaNaval,ahorcado};

    Categoria *categoriaRol = new Categoria("Juegos de rol","Los juegos de rol son experiencias narrativas en las que los jugadores asumen roles de personajes "
                                                             "ficticios en un mundo imaginario. Se caracterizan por la creación de historias y el desarrollo de "
                                                             "personajes a través de la interacción con otros jugadores y un director de juego.",
                                            "Narrativa, imaginación, interpretación de roles");

    Categoria *categoriaAventura = new Categoria("Juegos de aventura gráfica",
                                                 "Los juegos de aventura gráfica son aquellos en los que los"
                                                 " jugadores asumen el papel de un personaje principal y exploran"
                                                 " entornos detallados, interactúan con otros personajes y resuelven"
                                                 " acertijos para avanzar en la historia. Se centran en la narrativa y"
                                                 " la resolución de problemas.",
                                                 "Narrativa, resolución de acertijos, exploración");

    Categoria *categoriaEstrategia = new Categoria("Juegos de estrategia en tiempo real (RTS)",
                                                   "Los juegos de estrategia en tiempo real son aquellos"
                                                   " en los que los jugadores construyen bases, recolectan"
                                                   " recursos y entrenan unidades en tiempo real para enfrentarse"
                                                   " a sus oponentes. La rapidez de pensamiento y la toma de decisiones"
                                                   " son fundamentales para alcanzar la victoria.",
                                                   "Estrategia, competición, acción en tiempo real");
    this->categorias = {categoriaRol,categoriaAventura,categoriaEstrategia};
}

Usuario* BD::addUsuario(Usuario* usuario){
    auto it = find(this->usuarios.begin(),this->usuarios.end(),usuario);
    if (it == this->usuarios.end()) {
        this->usuarios.push_back(usuario);
        return usuario;
    } else {
        return *it;
    }
}

vector<Usuario*> BD::getUsuarios() const {
    return this->usuarios;
}

void BD::addCategoria(Categoria* categoria){
    auto it = find(this->categorias.begin(),this->categorias.end(),categoria);
    if (it == this->categorias.end()) {
        this->categorias.push_back(categoria);
    }
}

vector<Categoria*> BD::getCategorias() const {
    return this->categorias;
}

void BD::setCurrentUsuario(Usuario* currentUsuario){
    this->currentUsuario = currentUsuario;
}

Usuario* BD::getCurrentUsuario() const {
    return this->currentUsuario;
}

vector<VideoJuego*> BD::getVideoJuegos() const {
    return this->videoJuegos;
}

vector<VideoJuego*> BD::ordenarPorTitulo(bool invert) {
    sort(this->videoJuegos.begin(), this->videoJuegos.end(), [invert](const VideoJuego* a, const VideoJuego* b) {
        return invert ?  a->getNombre() < b->getNombre() : a->getNombre() > b->getNombre();
    });
    return this->videoJuegos;
}

vector<VideoJuego*> BD::ordenarPorFecha(bool invert) {
    sort(this->videoJuegos.begin(), this->videoJuegos.end(), [invert](VideoJuego* a,VideoJuego* b) {
        return invert ? a->getAnoLanzamiento() > b->getAnoLanzamiento() : a->getAnoLanzamiento() < b->getAnoLanzamiento();
    });
    return this->videoJuegos;
}

vector<VideoJuego*> BD::ordenarPorVecesJugado(bool invert) {
    sort(this->videoJuegos.begin(), this->videoJuegos.end(), [invert](const VideoJuego* a, const VideoJuego* b) {
        return invert ?  a->getVecesJugado() < b->getVecesJugado() : a->getVecesJugado() > b->getVecesJugado() ;
    });
    return this->videoJuegos;
}

vector<VideoJuego*> BD::filtrarPorPlataforma(const string& plataforma) {
    vector<VideoJuego*> juegosFiltrados;
    for (VideoJuego* videoJuego : this->videoJuegos) {
        if (videoJuego->getPlataforma() == plataforma) {
            juegosFiltrados.push_back(videoJuego);
        }
    }
    return juegosFiltrados.empty() ? this->videoJuegos : juegosFiltrados;
}

