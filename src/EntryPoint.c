#include <VapourSynth4.h>
#include <stdlib.h>

#include "CPU.h"


// Extra indirection to keep the parameter lists with the respective filters.


void mvsuperRegister(VSPlugin *plugin, const VSPLUGINAPI *vspapi);
void mvanalyseRegister(VSPlugin *plugin, const VSPLUGINAPI *vspapi);
void mvdegrainsRegister(VSPlugin *plugin, const VSPLUGINAPI *vspapi);
void mvcompensateRegister(VSPlugin *plugin, const VSPLUGINAPI *vspapi);
void mvrecalculateRegister(VSPlugin *plugin, const VSPLUGINAPI *vspapi);
void mvmaskRegister(VSPlugin *plugin, const VSPLUGINAPI *vspapi);
/*void mvfinestRegister(VSRegisterFunction registerFunc, VSPlugin *plugin);*/
/*void mvflowRegister(VSRegisterFunction registerFunc, VSPlugin *plugin);*/
/*void mvflowblurRegister(VSRegisterFunction registerFunc, VSPlugin *plugin);*/
/*void mvflowinterRegister(VSRegisterFunction registerFunc, VSPlugin *plugin);*/
/*void mvflowfpsRegister(VSRegisterFunction registerFunc, VSPlugin *plugin);*/
/*void mvblockfpsRegister(VSRegisterFunction registerFunc, VSPlugin *plugin);*/
/*void mvscdetectionRegister(VSRegisterFunction registerFunc, VSPlugin *plugin);*/
/*void mvdepanRegister(VSRegisterFunction registerFunc, VSPlugin *plugin);*/


uint32_t g_cpuinfo = 0;

VS_EXTERNAL_API(void)
VapourSynthPluginInit2(VSPlugin *plugin, const VSPLUGINAPI *vspapi) {
    const int packageVersion = atoi(PACKAGE_VERSION);

    vspapi->configPlugin("com.nodame.mvtools", "mv", "MVTools v" PACKAGE_VERSION, VS_MAKE_VERSION(packageVersion, 0), VS_MAKE_VERSION(VAPOURSYNTH_API_MAJOR, VAPOURSYNTH_API_MINOR), 0, plugin);

    mvsuperRegister(plugin, vspapi);
    mvanalyseRegister(plugin, vspapi);
    mvdegrainsRegister(plugin, vspapi);
    mvcompensateRegister(plugin, vspapi);
    mvrecalculateRegister(plugin, vspapi);
    mvmaskRegister(plugin, vspapi);
    /*mvfinestRegister(registerFunc, plugin);*/
    /*mvflowRegister(registerFunc, plugin);*/
    /*mvflowblurRegister(registerFunc, plugin);*/
    /*mvflowinterRegister(registerFunc, plugin);*/
    /*mvflowfpsRegister(registerFunc, plugin);*/
    /*mvblockfpsRegister(registerFunc, plugin);*/
    /*mvscdetectionRegister(registerFunc, plugin);*/
    /*mvdepanRegister(registerFunc, plugin);*/

    g_cpuinfo = cpu_detect();
}
