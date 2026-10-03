add_executable(SandboxApp main.cpp)

# Vincular el Sandbox con nuestro motor
target_link_libraries(SandboxApp PRIVATE AtaraxiaCore)