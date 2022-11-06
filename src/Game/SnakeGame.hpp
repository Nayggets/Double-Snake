#include "../Fruits/Fruitz.hpp"
#include "../Snake/Snake.hpp"
#include "../Body2D/Body.hpp"
#include "../Screen_Manager/Screen.hpp"
class SnakeGame{
    public:
        SnakeGame();
        ~SnakeGame();
        void run();

    private:
        Fruitz m_theMagicalFruit;
        Snake m_snakeOne;
        Snake m_snakeTwo;
        std::vector<Body> m_toCheckCollide;
        Screen m_screen;
        bool m_pause = false;
        bool m_quit = false;
        bool m_fullscreen = false;
        bool m_starting = true;
        bool m_snakeOneDead = false;
        bool m_snakeTwoDead = false;
        int m_moove = 0;
        int m_moove2 = 0;
        unsigned int m_tickAtStart = 0;
        unsigned int m_tickAtEnd = 0;
        double m_delta = 0;

    private:
        void startWait();
        void pauseWait();
        void checkProcessEvent();
        void launch();
        void globalDraw();
        void globalUpdate();
        void globalCheckCollide();

};