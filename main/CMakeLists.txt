add_executable(pico_emb main.c)

set_target_properties(pico_emb PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# pull in common dependencies
target_link_libraries(pico_emb pico_stdlib)

# Habilita o printf via USB (Serial)
pico_enable_stdio_usb(pico_emb 1)

# Desabilita o printf via UART (Pinos físicos), opcional mas recomendado
pico_enable_stdio_uart(pico_emb 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(pico_emb)
