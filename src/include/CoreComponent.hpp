#ifndef CORECOMPONENT_HPP
#define CORECOMPONENT_HPP

namespace glichess {
	class CoreComponent {
	public:
		CoreComponent() = default;
		CoreComponent(const CoreComponent&) = delete;
		CoreComponent(CoreComponent&&) = delete;
		CoreComponent& operator=(const CoreComponent&) = delete;
		CoreComponent& operator=(CoreComponent&&) = delete;
		virtual ~CoreComponent() = default;

		virtual void Initialize() = 0;
		virtual void Update() = 0;
	};
}

#endif