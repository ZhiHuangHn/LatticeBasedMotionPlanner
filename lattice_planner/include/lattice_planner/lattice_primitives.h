#ifndef LATTICE_PRIMITIVES_H
#define LATTICE_PRIMITIVES_H

#include <lattice_planner/pose.h>
#include <lattice_planner/velocity.h>
#include <lattice_planner/motion_constraints.h>
#include <lattice_planner/state.h>
#include <lattice_planner/state_discretizer.h>

namespace lattice_planner {

    class LatticePrims {
        public:

            LatticePrims(MotionConstraints motion_constraints);

            MotionConstraints getMotionConstraints();

            std::vector<Velocity> getReachableVelocities(
                    Velocity current_velocity, double time_delta);

            Pose getNextPose(Pose current, Velocity travel_vel,
                    double time_delta);

            std::vector<unsigned int> getTrajectoryIndices(
                    State *begin, 
                    DiscreteState end_i,
                    Velocity travel_vel,
                    StateDiscretizer *discretizer,
                    double time_inkr,
                    double time_delta);

        private:
            
            LatticePrims();

            MotionConstraints motion_constraints_;
    };

} /* namespace lattice_planner */

#endif /* LATTICE_PRIMITIVES_H */

