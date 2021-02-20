cmake_minimum_required(VERSION 3.16)

find_package(Boost COMPONENTS program_options REQUIRED)

add_executable(cosig
    main
    camera
    figure
    image
    light
    material
    parser
    transformation
 )

target_link_libraries(cosig
PRIVATE
    Boost::program_options
)