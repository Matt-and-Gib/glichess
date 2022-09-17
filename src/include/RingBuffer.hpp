#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

namespace glichess {
	template <typename T>
	class RingBuffer {
	public:
		explicit RingBuffer(const unsigned char desiredSize):
		data{new RingBufferData[desiredSize + METADATA_SIZE]} { //Nano 33 IoT has page size of 64 bytes!
			data[HEAD].metaData = START_INDEX;
			data[TAIL].metaData = START_INDEX;
			data[LENGTH].metaData = desiredSize;
		}

		~RingBuffer() {
			delete data; //todo: validate correct delete
		}

		void Push(const T addData) {
			if(data[HEAD] + 1 == data[LENGTH]) {
				//todo: log overwrite warning?
			}

			data[data[HEAD]++] = addData;
			if(data[HEAD] == (data[LENGTH] + METADATA_SIZE)) {
				data[HEAD] = START_INDEX;
			}
		}

		T&& Pop() {
			if(data[TAIL] == (data[LENGTH] + (METADATA_SIZE - 1))) {
				data[TAIL] = START_INDEX;
				return data[data[LENGTH] + (METADATA_SIZE - 1)];
			} else {
				return data[data[TAIL]++];
			}
		}

	private:
		union RingBufferData {
			unsigned char metaData;
			T data;
		};
		static constexpr const unsigned char HEAD = 0;
		static constexpr const unsigned char TAIL = 1;
		static constexpr const unsigned char LENGTH = 2;
		static constexpr const unsigned char METADATA_SIZE = 3;
		static constexpr const unsigned char START_INDEX = METADATA_SIZE;

		union RingBufferData* const data;
	};
}

#endif
