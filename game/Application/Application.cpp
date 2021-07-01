#include "Application.h"

using namespace se;

// Static vector initializing (window resolution)
Vector2u Application::resolution_ = Vector2u{0, 0};

Application::Application(unsigned int resolution_width, unsigned int resolution_height, const std::string& title) :
        window_ (new sf::RenderWindow{sf::VideoMode{resolution_width, resolution_height}, title}) {
    resolution_ = Vector2u{resolution_width, resolution_height};
}

void Application::launch() {
    sf::Event event;

    // Create sketch driver and initialize sketch assistant
    SketchDriver sketch_driver;
    SketchAssistant::sketch_driver_ = &sketch_driver;

    // Create graphical driver and initialize graphical assistant
    GraphicalDriver graphical_driver(window_);
    GraphicalAssistant::graphical_driver = &graphical_driver;
    
    // Create the time driver
    TimeDriver time_driver;
    TimeAssistant::time_driver_ = &time_driver;

    // Create the input driver
    InputDriver input_driver;
    InputAssistant::input_driver = &input_driver;

    unsigned long time = 0;
    unsigned long old_time = 0;
    unsigned long frames = 0;

    time_driver.restartClock();
    while (window_->isOpen()) {
        if (sketch_driver.getSketches() == 0) {
            window_->close();
        }

        while (window_->pollEvent(event)) {
            // Handle all events
            input_driver.handleEvent(event);

            switch (event.type) {
                case sf::Event::EventType::Closed:
                    window_->close();
                    break;
            }
        }

        window_->clear();

        // Update active sketches
        sketch_driver.updateSketches();
        // Collect all objects
        sketch_driver.collectObjects();

        // Draw all objects on the screen
        graphical_driver.drawObjects();

        // Display all objects on the screen
        window_->display();
        // Update state of keys
        input_driver.updateKeys();

        // Delete skectes that are no longer needed
        sketch_driver.deleteSketches();
        // Clear objects
        graphical_driver.clearObjects();

        // Count the passed time
        time = time_driver.getElapsedTime();
        //std::cout << "Time: " << time << std::endl;
        time_driver.setFrameTime(time - old_time);
        old_time = time;

        if (old_time >= 1000000) {
            // One second passed
            // std::cout << "FPS: " << frames << std::endl;
            frames = 0;
            old_time = 0;
            time = 0;
            time_driver.restartClock();
        } else
            frames++; // the frames ended
    }
}

Application::~Application() {
    delete window_;
}