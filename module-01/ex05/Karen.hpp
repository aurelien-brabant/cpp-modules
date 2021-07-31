#ifndef KAREN_H
# define KAREN_H
# include <string>

class Karen {
	public:
		typedef enum {
			MODE_DEBUG = 0,
			MODE_INFO = 1,
			MODE_WARNING = 2,
			MODE_ERROR = 3,
			MODE_MAX = 4,
		} intMode;

		Karen(void);
		static intMode	getIntMode(const std::string &mode);
		void			complain(std::string level);

	private:
		typedef void (Karen::* KarenComplain)(void) const;
		KarenComplain complains[MODE_MAX];

		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;
};

#endif
