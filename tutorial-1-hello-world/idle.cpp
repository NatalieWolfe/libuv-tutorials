
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <uv.h>

void wait_for_a_while( uv_idle_t* handle ){
    static std::int64_t counter = 0;
    if( ++counter >= 10e6 ){
        std::cout << "Done idling after " << counter << " ticks." << std::endl;
        uv_idle_stop( handle );
    }
}

int main( void ){
    // Allocate and initialize the loop.
    std::cout << "Allocating loop." << std::endl;
    uv_loop_t* loop = (uv_loop_t*)std::malloc( sizeof( uv_loop_t ) );
    uv_loop_init( loop );

    // Create our idle handle and set the callback.
    std::cout << "Creating idle handle." << std::endl;
    uv_idle_t idler;
    uv_idle_init( loop, &idler );
    uv_idle_start( &idler, &wait_for_a_while );

    // Run the loop.
    std::cout << "Starting loop." << std::endl;
    uv_run( loop, UV_RUN_DEFAULT );
    std::cout << "Loop completed." << std::endl;

    // Idle doesn't get closed, just stopped.

    // Close the loop and free our resources.
    uv_loop_close( loop );
    std::free( loop );

    return 0;
}
