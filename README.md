# Quest System based on L-System Integration
 
An experimental quests procedural generation for master's thesis.

The repository contains two parts: a prototype and a simple example of adaptive ingame generation pipeline based on Lindenmayer System.

---

### lsystem-quest-generation (Prototype Project)

- **Description:** Pure C++ implementation of an L-system generator, used to produce procedural token sequences and collect data for test.
- **Build Instructions:**
    1. Clone repository.
    2. Open `lsystem-quest-generation.sln` in Visual Studio.
    3. Select the appropriate configuration and build the solution.

---

### LSystemSample (Example Unreal Project)

- **Description:** Unreal Engine 5 project demonstrating ingame integration of the C++ L-system for a quest generation system.
- **Build Instructions:**
    1. Clone repository
    2. Open `LSystemSample/LSystemSample.uproject` in Unreal Engine 5.
    3. Generate Visual Studio project files (if needed).
    4. Open and build the required solution manually in Development Editor, Win64.
    5. Launch the editor.

---

## Dependencies

- C++20
- Unreal Engine 5.4.4+

## Future Improvements (TODO list)

- Improved interface for quests designing
- Ingame debug and analytics
- Recreation of a system as an Unreal Engine plugin
- More advanced branching logic (conditions, player choices)
- Replication support
- UI polish and quest tracking widgets
