#ifndef CORECOMPONENT_H
#define CORECOMPONENT_H

namespace glichess {
	class CoreComponent {
	public:
		virtual void Initialize() = 0;
		virtual void Update() = 0;
	};
}

#endif