#include "Core/Application.hpp"

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    auto app = std::make_unique<Ataraxia::Application>();
    app->Run();

    return 0;
}