#pragma once

namespace bunny {
	struct MemoryAllocation {
		void* address;
		size_t size;
		MemoryAllocation* next;
	};

	class MemoryTracker {
	public:
		void Add(void* address, size_t size);
		void Remove(void* address, size_t size);
		void DisplayInfo();
	private:
		size_t m_bytesAllocated = 0;
		size_t m_numAllocations = 0;
	};

	extern bunny::MemoryTracker g_memoryTracker;
}