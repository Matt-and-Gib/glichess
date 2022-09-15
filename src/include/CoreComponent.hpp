#ifndef CORECOMPONENT_H
#define CORECOMPONENT_H

namespace glichess {
	class CoreComponent {
	public:
		virtual void StartUp() = 0;
		virtual void Update() = 0;
	};
}

#endif