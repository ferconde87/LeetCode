class UndergroundSystem
  def initialize()
      @checkin = {}
      @travel_data = {} # dict with key = "#{startStation}#{endStation}", value = total_times, total_travels
      # total_times is the total time of all the travels from startStation to endStation
      # total_travels is the total amount of travels from startStation to endStation
  end


=begin
  :type id: Integer
  :type station_name: String
  :type t: Integer
  :rtype: Void
=end
  def check_in(id, station_name, t)
      @checkin[id] = [station_name, t]
  end


=begin
  :type id: Integer
  :type station_name: String
  :type t: Integer
  :rtype: Void
=end
  def check_out(id, station_name, t)
      station = "#{@checkin[id][0]}-#{station_name}"
      time = t - @checkin[id][1]
      if !@travel_data.include?(station)
          @travel_data[station] = [time, 1]
      else
          data = @travel_data[station]
          data[0] += time
          data[1] += 1
      end
  end


=begin
  :type start_station: String
  :type end_station: String
  :rtype: Float
=end
  def get_average_time(start_station, end_station)
      time_travel = @travel_data["#{start_station}-#{end_station}"]
      time_travel[0].to_f / time_travel[1]
  end


end

# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem.new()
# obj.check_in(id, station_name, t)
# obj.check_out(id, station_name, t)
# param_3 = obj.get_average_time(start_station, end_station)
