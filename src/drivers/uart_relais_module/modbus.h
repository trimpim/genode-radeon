

#ifndef __DRIVERS__UART_RELAIS_MODULE__MODBUS_H__
#define __DRIVERS__UART_RELAIS_MODULE__MODBUS_H__

/* Genode includes */
#include <base/env.h>
#include <base/stdint.h>
#include <util/string.h>
#include <terminal_session/connection.h>

namespace Relais_module
{
	using namespace Genode;

	class Modbus;
}


class Relais_module::Modbus
{
	private:

		Env                  &_env;
		bool                  _verbose;
		Terminal::Connection  _serial { _env };

		uint8_t               _tx_buffer[255] { };
		uint8_t               _rx_buffer[255] { };

		size_t                _tx_length      { 0 };
		size_t                _rx_length      { 0 };

		// serial terminal connection here or extern?

		struct Crc_result {
			uint8_t  high;
			uint8_t  low;
		};

		/**
		 * brief Calculate MODBUS crc
		 *
		 * \param     data: Data
		 * \return:   List CRC high Byte, CRC low Byte
		*/
		Crc_result _crc(Const_byte_range_ptr const &data);

	public:

		Modbus(Env &env, bool verbose) :
			_env { env }, _verbose { verbose }
		{ }

		/**
		 * MODBUS send
		 *
		 * \param tx_data: List data (int)
		 * \param append_crc_to_frame: Append CRC to TX frame
		 */
		void send(Const_byte_range_ptr const &tx_data, bool append_crc_to_frame = true);

		/**
		 * MODBUS receive
		 *
		 * \param rx_length: Receive length
		 * \param List received data (int)
		 */
		void receive(Genode::Byte_range_ptr const &out, uint8_t rx_length);
};


#endif /* __DRIVERS__UART_RELAIS_MODULE__MODBUS_H__ */
