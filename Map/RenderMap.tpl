namespace map
{
    template<class T>
    RenderMap<T>::RenderMap(unsigned int width, unsigned int height, bool depthBuffer) : RenderTexture()
    {
        create(width,height,depthBuffer);
    };



    template<class T>
    void RenderMap<T>::draw(sf::RenderTarget &target,sf::RenderStates states)
    {
        /* create the map rendering */
        RenderTexture::clear();
        _map.draw(*this);
        RenderTexture::display();
        /* show it to the target */
        target.draw(sprite,states);
    };

    template<class T>
    void RenderMap<T>::create(unsigned int width, unsigned int height, bool depthBuffer)
    {
        RenderTexture::create(width,height,depthBuffer);
        sprite.setTexture(RenderTexture::getTexture());
    };

    template<class T>
    template<typename ... Args >
    void RenderMap<T>::move(Args&& ... args)
    {
        sf::View view(RenderTexture::getView());
        view.move(args...);
        RenderTexture::setView(view);
    };

    template<class T>
    void RenderMap<T>::setViewPosition(const int& x,const int& y)
    {
        sf::View view(RenderTexture::getView());
        view.setCenter(T::mapCoordsToPixel(x,y));
        RenderTexture::setView(view);
    };


    template<class T>
    template<typename ... Args >
    void RenderMap<T>::setOrigin(Args&& ... args)
    {
        sprite.setOrigin(std::forward<Args&>(args) ...);
    };

    template<class T>
    template<typename ... Args >
    void RenderMap<T>::setPosition(Args&& ... args)
    {
        sprite.setPosition(std::forward<Args&>(args) ...);
    };

    template<class T>
    template<typename ... Args >
    sf::Vector2f RenderMap<T>::getPosition(Args&& ... args)
    {
        return sprite.getPosition(std::forward<Args&>(args) ...);
    };

    template<class T>
    template<typename ... Args>
    sf::Vector2i RenderMap<T>::mapPixelToCoords(Args&& ... args)
    {
        sf::Vector2f mouss(RenderTexture::mapPixelToCoords(args...) - sprite.getPosition());
        return T::mapPixelToCoords(mouss.x,mouss.y);
    };

    template<class T>
    template<typename ... Args>
    sf::Vector2i RenderMap<T>::mapCoordsToPixel(Args&& ... args)
    {
        return T::mapCoordsToPixel(args...);
    };


};
