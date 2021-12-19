# Runtime: 84 ms, faster than 90.91% of Ruby online submissions for Design Parking System.
# Memory Usage: 210.4 MB, less than 59.09% of Ruby online submissions for Design Parking System.

class ParkingSystem
  =begin
      :type big: Integer
      :type medium: Integer
      :type small: Integer
  =end
      def initialize(big, medium, small)
          @big = big
          @medium = medium
          @small = small
      end
  
  =begin
      :type car_type: Integer
      :rtype: Boolean
  =end
      def add_car(car_type)
          case car_type
          when 1
              #big
              return false if @big == 0
              @big -= 1
          when 2
              #medium
              return false if @medium == 0
              @medium -= 1
          when 3
              #small
              return false if @small == 0
              @small -= 1
          else
              return false
          end
          return true
      end  
  end
  
  # Your ParkingSystem object will be instantiated and called as such:
  # obj = ParkingSystem.new(big, medium, small)
  # param_1 = obj.add_car(car_type)


# Runtime: 88 ms, faster than 77.27% of Ruby online submissions for Design Parking System.
# Memory Usage: 210.6 MB, less than 36.36% of Ruby online submissions for Design Parking System.
class ParkingSystem
  =begin
      :type big: Integer
      :type medium: Integer
      :type small: Integer
  =end
  def initialize(big, medium, small)
      @slots = {
          1 => big,
          2 => medium,
          3 => small,
      }
  end
  
  =begin
      :type car_type: Integer
      :rtype: Boolean
  =end
  def add_car(car_type)
      return false if @slots[car_type] == 0
      @slots[car_type] -= 1
      true
  end
  end
