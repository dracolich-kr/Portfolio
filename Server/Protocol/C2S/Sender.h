#pragma once

namespace  Protocol::C2S
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
