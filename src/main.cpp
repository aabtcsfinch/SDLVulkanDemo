#include <iostream>
#include "../libs/SDL2/include/SDL.h"

#define GLEW_STATIC
#include <GL/glew.h>
#include "../libs/SDL2/include/SDL_opengl.h"
#include "../libs/glm/glm/glm.hpp"
#include "../libs/glm/glm/gtc/matrix_transform.hpp"
#include "../libs/glm/glm/gtc/type_ptr.hpp"
#include "../libs/asio/include/asio.hpp"
#include "../libs/asio/include/asio/ts/buffer.hpp"
#include "../libs/asio/include/asio/ts/internet.hpp"

const GLint WIDTH = 1920, HEIGHT = 1080;


int main()
{
    SDL_Init( SDL_INIT_EVERYTHING );

    /* SDL and OpenGL attributes */
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, 8);

    SDL_Window *window = SDL_CreateWindow( "SDL2 Vulkan OpenGL and ASIO Game Template v1.0", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

    SDL_GLContext glcontext = SDL_GL_CreateContext( window );

    glewExperimental = GL_TRUE;

    /* initialize GLEW */
    if ( GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }

    glViewport(0, 0, WIDTH, HEIGHT);

    SDL_Event windowEvent;

    while( true )
    {
        if( SDL_PollEvent( &windowEvent ) )
        {
            if ( windowEvent.type == SDL_QUIT) break;
        }

        glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        /* draw OpenGL */
        SDL_GL_SwapWindow( window );
        asio::io_context io_context;
        asio::error_code ec;
        asio::ip::tcp::endpoint endpoint(asio::ip::make_address("93.184.216.34", ec), 80);
        asio::ip::tcp::socket socket( io_context );
        socket.connect(endpoint, ec);

        if(!ec)
        {
            std::cout << "We're connected!" << std::endl;
        }
        else
        {
            std::cout << "Failed to connect to address: \n" << ec.message() << std::endl;
        }
    }

    SDL_GL_DeleteContext( glcontext );
    SDL_DestroyWindow( window );
    SDL_Quit();

    return 0;
}