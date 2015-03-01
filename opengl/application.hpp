#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

/**
 * @brief クラスの説明．
 */

struct window_param
{
    int  width_;
    int  height_;
    std::string title_;

    window_param( int width, int height, const char* title ) :
        width_( width ),
        height_( height ),
        title_( title )
    {}
};

class application
{
public:
    /*===========================================================================*/
    /**
     * コンストラクタ．
     */
    application( int width, int heigth, const char* title = "" );

    bool init();

    /*===========================================================================*/
    /**
     * 関数の説明．
     *
     * @param [in]  name 引数の説明 ．
     * @return   戻り値の説明 ．
     */
    void run();

private:
    void display();

private:
    /** @brief 変数の説明 */
    window_param window_param_;
    GLFWwindow* window_;
};

/*========= End of File =====================================================*/

