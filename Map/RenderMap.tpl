namespace map
{
    template<class T>
    RenderMap<T>::RenderMap(unsigned int width, unsigned int height, bool depthBuffer,const int& X,const int Y) : RenderTexture()
    {
        create(width,height,depthBuffer);
        //move(X,Y);
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
        view.setCenter(T::toGlobal(x,y));
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
    sf::Vector2i RenderMap<T>::toLocal(Args&& ... args)
    {
        sf::Vector2f mouss(RenderTexture::mapPixelToCoords(args...) - sprite.getPosition());
        return T::toLocal(mouss.x,mouss.y);
    };

    template<class T>
    template<typename ... Args>
    sf::Vector2i RenderMap<T>::toGlobal(Args&& ... args)
    {
        return T::toGlobal(args...);
    };


};