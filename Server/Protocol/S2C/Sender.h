#pragma once

namespace  Protocol::S2C
{
    class Sender
    {
    public:
        Sender(Network::SharedSession session)
            : mSession(session)
        {}
        virtual ~Sender() {}



    private:
        Network::SharedSession mSession;
    };

}
