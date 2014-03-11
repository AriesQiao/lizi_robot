#ifndef _ROS_SERVICE_set_parameters_h
#define _ROS_SERVICE_set_parameters_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace lizi
{

static const char SET_PARAMETERS[] = "lizi/set_parameters";

  class set_parametersRequest : public ros::Msg
  {
    public:
      float kp;
      float ki;
      float kd;
      float alpha;
      int32_t control_dt;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_kp;
      u_kp.real = this->kp;
      *(outbuffer + offset + 0) = (u_kp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kp);
      union {
        float real;
        uint32_t base;
      } u_ki;
      u_ki.real = this->ki;
      *(outbuffer + offset + 0) = (u_ki.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ki.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ki.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ki.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ki);
      union {
        float real;
        uint32_t base;
      } u_kd;
      u_kd.real = this->kd;
      *(outbuffer + offset + 0) = (u_kd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kd);
      union {
        float real;
        uint32_t base;
      } u_alpha;
      u_alpha.real = this->alpha;
      *(outbuffer + offset + 0) = (u_alpha.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alpha.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alpha.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alpha.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alpha);
      union {
        int32_t real;
        uint32_t base;
      } u_control_dt;
      u_control_dt.real = this->control_dt;
      *(outbuffer + offset + 0) = (u_control_dt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_control_dt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_control_dt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_control_dt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->control_dt);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_kp;
      u_kp.base = 0;
      u_kp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_kp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_kp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_kp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->kp = u_kp.real;
      offset += sizeof(this->kp);
      union {
        float real;
        uint32_t base;
      } u_ki;
      u_ki.base = 0;
      u_ki.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ki.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ki.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ki.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ki = u_ki.real;
      offset += sizeof(this->ki);
      union {
        float real;
        uint32_t base;
      } u_kd;
      u_kd.base = 0;
      u_kd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_kd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_kd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_kd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->kd = u_kd.real;
      offset += sizeof(this->kd);
      union {
        float real;
        uint32_t base;
      } u_alpha;
      u_alpha.base = 0;
      u_alpha.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alpha.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alpha.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alpha.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alpha = u_alpha.real;
      offset += sizeof(this->alpha);
      union {
        int32_t real;
        uint32_t base;
      } u_control_dt;
      u_control_dt.base = 0;
      u_control_dt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_control_dt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_control_dt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_control_dt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->control_dt = u_control_dt.real;
      offset += sizeof(this->control_dt);
     return offset;
    }

    const char * getType(){ return SET_PARAMETERS; };
    const char * getMD5(){ return "20d8462c52ee82d2740a49fc3f4d457a"; };

  };

  class set_parametersResponse : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SET_PARAMETERS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class set_parameters {
    public:
    typedef set_parametersRequest Request;
    typedef set_parametersResponse Response;
  };

}
#endif
