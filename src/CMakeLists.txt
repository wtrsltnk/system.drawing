
add_library(system.drawing
    Bitmap.cpp
    Image.cpp
    stb.cpp
    stb_image.h
    stb_image_resize.h
    stb_image_write.h
    )

target_include_directories(system.drawing
    PUBLIC
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ../include
    )

target_compile_features(system.drawing
    PRIVATE
        cxx_auto_type
        cxx_nullptr
        cxx_range_for
    )

install(
    TARGETS
        system.drawing
    EXPORT
        system.drawing
    DESTINATION
        "lib"
    )

install(
    FILES
        ${system.drawing_SOURCE_DIR}/include/system.drawing/system.drawing.bitmap.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/system.drawing.color.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/system.drawing.graphicsunit.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/system.drawing.image.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/system.drawing.pointf.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/system.drawing.rectangle.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/system.drawing.rectanglef.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/system.drawing.rotatefliptype.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/system.drawing.size.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/system.drawing.sizef.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/imaging/system.drawing.imaging.bitmapdata.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/imaging/system.drawing.imaging.colorpalette.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/imaging/system.drawing.imaging.encoderparameter.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/imaging/system.drawing.imaging.encoderparameters.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/imaging/system.drawing.imaging.imagecodecinfo.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/imaging/system.drawing.imaging.imageformat.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/imaging/system.drawing.imaging.imagelockmode.h
        ${system.drawing_SOURCE_DIR}/include/system.drawing/imaging/system.drawing.imaging.pixelformat.h

    DESTINATION
        "include/system.drawing"
    )

install(
    EXPORT
        system.drawing
    FILE
        system.drawing-config.cmake
    DESTINATION
        "cmake"
    )
