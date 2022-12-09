#ifndef RENDERER_H
#define RENDERER_H


class Renderer {
    public:

        Renderer(int width, int height, double viewportWidth): 
            outputWidth(width), 
            outputHeight(height), 
            viewportWidth(viewportWidth),
            viewportHeight(viewportWidth * height / width) {}

        void render() const;

    private:
        int outputWidth;
        int outputHeight;

        double viewportWidth;
        double viewportHeight;
};


#endif