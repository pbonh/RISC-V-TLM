file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/inc/*.h")
add_library(riscv_tlm_sim
    A_extension.cpp
    CPU.cpp
    MemoryInterface.cpp
    Timer.cpp
    BASE_ISA.cpp
    extension_base.cpp
    M_extension.cpp
    Trace.cpp
    BusCtrl.cpp
    Instruction.cpp
    Performance.cpp
    C_extension.cpp
    Log.cpp
    Registers.cpp
    Memory.cpp
    Simulator.cpp
    ${HEADER_LIST})

target_include_directories(riscv_tlm_sim PUBLIC /usr/local/systemc-2.3.3)
target_include_directories(riscv_tlm_sim PUBLIC ${PROJECT_SOURCE_DIR}/inc)

# This depends on (header only) boost
# target_link_libraries(verific_util PRIVATE Boost::boost)

# All users of this library will need at least C++17
target_compile_features(riscv_tlm_sim PUBLIC cxx_std_11)

# IDEs should put the headers in a nice place
# source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
