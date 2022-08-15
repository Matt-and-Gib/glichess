#ifndef CORECOMPONENT_H
#define CORECOMPONENT_H

namespace gleechess {
	class CoreComponent {
	public:
		virtual void StartUp() = 0;
		virtual void Update() = 0;
	};
}

#endif