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
        /*fruit*/
        Fruitz m_theMagicalFruit;
        /*snake*/
        Snake m_snakeOne;
        Snake m_snakeTwo;
        /*collision*/
        std::vector<Body> m_toCheckCollide;
        /*Screen*/
        Screen m_screen;
        
        /*Menu*/
        bool m_pause = false;
        bool m_run = false;
        bool m_quit = false;
        bool m_starting = true;
        bool m_snakeOneDead = false;
        bool m_snakeTwoDead = false;
        bool m_endMenu = false;
        
        /*Data for game running*/
        int m_moove = 0;
        int m_moove2 = 0;
        unsigned int m_tickAtStart = 0;
        unsigned int m_tickAtEnd = 0;

        /*option*/        
        bool m_fullscreen = false;
        double m_delta = 0;
        
    private:
        void startWait();
        void pauseWait();
        void checkProcessEvent();
        void launch();
        void globalDraw();
        void globalUpdate();
        void globalCheckCollide();
        void gameOver();
};