// 实现以下类的成员方法，注意在类外部实现成员方法，注意模板的语法
template<typename T>
class Grid
{
public:
	Grid(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
	Grid(const Grid<T>& src);
	template<typename E>
	Grid(const Grid<E>& src);
	~Grid();
	Grid<T>& operator=(const Grid<T>& rhs);
	template<typename E>
	Grid<T>& operator=(const Grid<E>& rhs);
	void setElementAt(size_t x, size_t y, const T& inElem);
	T& getElementAt(size_t x, size_t y);
	const T& getElementAt(size_t x, size_t y) const;
	size_t getHeight()const;
	size_t getWidth()const;
private:
	void copyFrom(const Grid<T> &src);
	template<typename E>
	void copyFrom(const Grid<E>& src);
	T **mCells;
	size_t mWidth;
	size_t mHeight;
	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;
};