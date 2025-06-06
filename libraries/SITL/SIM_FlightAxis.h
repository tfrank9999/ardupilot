/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
  simulator connection for ardupilot version of FlightAxis
*/

#pragma once

#include <AP_HAL/AP_HAL_Boards.h>
#include "SIM_config.h"

#if AP_SIM_FLIGHTAXIS_ENABLED

#include <AP_HAL/utility/Socket_native.h>

#include "SIM_Aircraft.h"

namespace SITL {

/*
  a FlightAxis simulator
 */
class FlightAxis : public Aircraft {
public:
    FlightAxis(const char *frame_str);

    static const struct AP_Param::GroupInfo var_info[];

    /* update model by one time step */
    void update(const struct sitl_input &input) override;

    /* static object creator */
    static Aircraft *create(const char *frame_str) {
        return NEW_NOTHROW FlightAxis(frame_str);
    }

    struct state {
        double rcin[12];
        double m_airspeed_MPS;
        double m_altitudeASL_MTR;
        double m_altitudeAGL_MTR;
        double m_groundspeed_MPS;
        double m_pitchRate_DEGpSEC;
        double m_rollRate_DEGpSEC;
        double m_yawRate_DEGpSEC;
        double m_azimuth_DEG;
        double m_inclination_DEG;
        double m_roll_DEG;
        double m_aircraftPositionX_MTR;
        double m_aircraftPositionY_MTR;
        double m_velocityWorldU_MPS;
        double m_velocityWorldV_MPS;
        double m_velocityWorldW_MPS;
        double m_velocityBodyU_MPS;
        double m_velocityBodyV_MPS;
        double m_velocityBodyW_MPS;
        double m_accelerationWorldAX_MPS2;
        double m_accelerationWorldAY_MPS2;
        double m_accelerationWorldAZ_MPS2;
        double m_accelerationBodyAX_MPS2;
        double m_accelerationBodyAY_MPS2;
        double m_accelerationBodyAZ_MPS2;
        double m_windX_MPS;
        double m_windY_MPS;
        double m_windZ_MPS;
        double m_propRPM;
        double m_heliMainRotorRPM;
        double m_batteryVoltage_VOLTS;
        double m_batteryCurrentDraw_AMPS;
        double m_batteryRemainingCapacity_MAH;
        double m_fuelRemaining_OZ;
        double m_isLocked;
        double m_hasLostComponents;
        double m_anEngineIsRunning;
        double m_isTouchingGround;
        double m_currentAircraftStatus;
        double m_currentPhysicsTime_SEC;
        double m_currentPhysicsSpeedMultiplier;
        double m_orientationQuaternion_X;
        double m_orientationQuaternion_Y;
        double m_orientationQuaternion_Z;
        double m_orientationQuaternion_W;
        double m_flightAxisControllerIsActive;
        double m_resetButtonHasBeenPressed;
    } state;

    static const uint16_t num_keys = sizeof(state)/sizeof(double);

    struct keytable {
        const char *key;
        double &ref;
    } keytable[num_keys] = {
        { "item", state.rcin[0] },
        { "item", state.rcin[1] },
        { "item", state.rcin[2] },
        { "item", state.rcin[3] },
        { "item", state.rcin[4] },
        { "item", state.rcin[5] },
        { "item", state.rcin[6] },
        { "item", state.rcin[7] },
        { "item", state.rcin[8] },
        { "item", state.rcin[9] },
        { "item", state.rcin[10] },
        { "item", state.rcin[11] },
        { "m-airspeed-MPS", state.m_airspeed_MPS },
        { "m-altitudeASL-MTR", state.m_altitudeASL_MTR },
        { "m-altitudeAGL-MTR", state.m_altitudeAGL_MTR },
        { "m-groundspeed-MPS", state.m_groundspeed_MPS },
        { "m-pitchRate-DEGpSEC", state.m_pitchRate_DEGpSEC },
        { "m-rollRate-DEGpSEC", state.m_rollRate_DEGpSEC },
        { "m-yawRate-DEGpSEC", state.m_yawRate_DEGpSEC },
        { "m-azimuth-DEG", state.m_azimuth_DEG },
        { "m-inclination-DEG", state.m_inclination_DEG },
        { "m-roll-DEG", state.m_roll_DEG },
        { "m-aircraftPositionX-MTR", state.m_aircraftPositionX_MTR },
        { "m-aircraftPositionY-MTR", state.m_aircraftPositionY_MTR },
        { "m-velocityWorldU-MPS", state.m_velocityWorldU_MPS },
        { "m-velocityWorldV-MPS", state.m_velocityWorldV_MPS },
        { "m-velocityWorldW-MPS", state.m_velocityWorldW_MPS },
        { "m-velocityBodyU-MPS", state.m_velocityBodyU_MPS },
        { "m-velocityBodyV-MPS", state.m_velocityBodyV_MPS },
        { "m-velocityBodyW-MPS", state.m_velocityBodyW_MPS },
        { "m-accelerationWorldAX-MPS2", state.m_accelerationWorldAX_MPS2 },
        { "m-accelerationWorldAY-MPS2", state.m_accelerationWorldAY_MPS2 },
        { "m-accelerationWorldAZ-MPS2", state.m_accelerationWorldAZ_MPS2 },
        { "m-accelerationBodyAX-MPS2", state.m_accelerationBodyAX_MPS2 },
        { "m-accelerationBodyAY-MPS2", state.m_accelerationBodyAY_MPS2 },
        { "m-accelerationBodyAZ-MPS2", state.m_accelerationBodyAZ_MPS2 },
        { "m-windX-MPS", state.m_windX_MPS },
        { "m-windY-MPS", state.m_windY_MPS },
        { "m-windZ-MPS", state.m_windZ_MPS },
        { "m-propRPM", state.m_propRPM },
        { "m-heliMainRotorRPM", state.m_heliMainRotorRPM },
        { "m-batteryVoltage-VOLTS", state.m_batteryVoltage_VOLTS },
        { "m-batteryCurrentDraw-AMPS", state.m_batteryCurrentDraw_AMPS },
        { "m-batteryRemainingCapacity-MAH", state.m_batteryRemainingCapacity_MAH },
        { "m-fuelRemaining-OZ", state.m_fuelRemaining_OZ },
        { "m-isLocked", state.m_isLocked },
        { "m-hasLostComponents", state.m_hasLostComponents },
        { "m-anEngineIsRunning", state.m_anEngineIsRunning },
        { "m-isTouchingGround", state.m_isTouchingGround },
        { "m-currentAircraftStatus", state.m_currentAircraftStatus },
        { "m-currentPhysicsTime-SEC", state.m_currentPhysicsTime_SEC },
        { "m-currentPhysicsSpeedMultiplier", state.m_currentPhysicsSpeedMultiplier },
        { "m-orientationQuaternion-X", state.m_orientationQuaternion_X },
        { "m-orientationQuaternion-Y", state.m_orientationQuaternion_Y },
        { "m-orientationQuaternion-Z", state.m_orientationQuaternion_Z },
        { "m-orientationQuaternion-W", state.m_orientationQuaternion_W },
        { "m-flightAxisControllerIsActive", state.m_flightAxisControllerIsActive },
        { "m-resetButtonHasBeenPressed", state.m_resetButtonHasBeenPressed },
    };

private:
    bool soap_request_start(const char *action, const char *fmt, ...);
    char *soap_request_end(uint32_t timeout_ms);
    void exchange_data(const struct sitl_input &input);
    void parse_reply(const char *reply);

    void update_loop(void);
    void report_FPS(void);
    void socket_creator(void);

    struct sitl_input last_input;

    AP_Int32 _options;

    enum class Option : uint32_t{
        ResetPosition = (1U<<0),
        Rev4Servos    = (1U<<1),
        HeliDemix     = (1U<<2),
        SilenceFPS    = (1U<<3),
    };

    // return true if an option is set
    bool option_is_set(Option option) const {
        return (uint32_t(option) & uint32_t(_options)) != 0;
    }

    double average_frame_time_s;
    double extrapolated_s;
    double initial_time_s;
    double last_time_s;
    bool controller_started;
    uint32_t glitch_count;
    uint64_t frame_counter;
    uint64_t activation_frame_counter;
    uint64_t socket_frame_counter;
    uint64_t last_socket_frame_counter;
    double last_frame_count_s;
    Vector3d position_offset;
    Vector3f last_velocity_ef;

    const char *controller_ip = "127.0.0.1";
    uint16_t controller_port = 18083;

    // a list of sockets used to reduce inter-packet latency
    ObjectBuffer_TS<SocketAPM_native*> socks{2};
    SocketAPM_native *sock;

    char replybuf[10000];
    pid_t socket_pid;
    uint32_t sock_error_count;
    double last_recv_sec;
};


} // namespace SITL

#endif // AP_SIM_FLIGHTAXIS_ENABLED
