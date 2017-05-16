#include "Parselmouth.h"

namespace py = pybind11;

namespace parselmouth {

void initSoundEnums(PraatBindings &bindings)
{
	// TODO Export befóre using default values for them
	// TODO Can be nested within Sound? Valid documentation (i.e. parselmouth.Sound.WindowShape instead of parselmouth.WindowShape)?

	bindings.get<WindowShape>()
			.value("RECTANGULAR", kSound_windowShape_RECTANGULAR)
			.value("TRIANGULAR", kSound_windowShape_TRIANGULAR)
			.value("PARABOLIC", kSound_windowShape_PARABOLIC)
			.value("HANNING", kSound_windowShape_HANNING)
			.value("HAMMING", kSound_windowShape_HAMMING)
			.value("GAUSSIAN1", kSound_windowShape_GAUSSIAN_1)
			.value("GAUSSIAN2", kSound_windowShape_GAUSSIAN_2)
			.value("GAUSSIAN3", kSound_windowShape_GAUSSIAN_3)
			.value("GAUSSIAN4", kSound_windowShape_GAUSSIAN_4)
			.value("GAUSSIAN5", kSound_windowShape_GAUSSIAN_5)
			.value("KAISER1", kSound_windowShape_KAISER_1)
			.value("KAISER2", kSound_windowShape_KAISER_2)
			;
	make_implicitly_convertible_from_string<WindowShape>(bindings.get<WindowShape>(), true);

	bindings.get<AmplitudeScaling>()
			.value("INTEGRAL", kSounds_convolve_scaling_INTEGRAL)
			.value("SUM", kSounds_convolve_scaling_SUM)
			.value("NORMALIZE", kSounds_convolve_scaling_NORMALIZE)
			.value("PEAK_0_99", kSounds_convolve_scaling_PEAK_099)
			;
	make_implicitly_convertible_from_string<AmplitudeScaling>(bindings.get<AmplitudeScaling>(), true);

	bindings.get<SignalOutsideTimeDomain>()
			.value("ZERO", kSounds_convolve_signalOutsideTimeDomain_ZERO)
			.value("SIMILAR", kSounds_convolve_signalOutsideTimeDomain_SIMILAR)
			;
	make_implicitly_convertible_from_string<SignalOutsideTimeDomain>(bindings.get<SignalOutsideTimeDomain>(), true);
}

} // namespace parselmouth