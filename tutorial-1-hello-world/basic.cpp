
#include <cstdlib>
#include <iostream>
#include <uv.h>

int main( void ){
    std::cout << "Allocating loop." << std::endl;

    // Allocate and initialize the loop.
    uv_loop_t* loop = (uv_loop_t*)std::malloc( sizeof( uv_loop_t ) );
    uv_loop_init( loop );

    // Run the loop (in this example, it will return immediately because there are no events to
    // process).
    std::cout << "Starting loop." << std::endl;
    uv_run( loop, UV_RUN_DEFAULT );
    std::cout << "Loop completed." << std::endl;

    // Close the loop and free our resources.
    uv_loop_close( loop );
    std::free( loop );

    return 0;
}
