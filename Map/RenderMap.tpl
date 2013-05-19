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


};
