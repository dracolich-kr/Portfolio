#include "Pch.h"
#include <thread>

int main()
{
    //auto machine = std::make_shared<HFSM::Machine<StateType, TriggerType>>();
    std::chrono::milliseconds ms(10);
    while (1)
    {
        {
            SharedSkill skill = std::make_shared<Skill>(nullptr);
            skill->InitHFSM();
            skill->Release();
            skill = nullptr;
        }
        std::this_thread::sleep_for(ms);
    }

    //auto root = machine->GetRoot();
    //auto spawn = std::make_shared<HFSM::Spawn>(machine, root);
    //machine->AddState(spawn);
    //
    //auto alive = std::make_shared<HFSM::Alive>(machine, root);
    //machine->AddState(alive);
    //
    //auto dead = std::make_shared<HFSM::Dead>(machine, root);
    //machine->AddState(dead);

    return 0;
}

